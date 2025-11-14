#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VTJUT_UART_CTRL.h"
#include <iostream>
#include <random>
#include <cassert>

using namespace std;

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static VTJUT_UART_CTRL* top;

// 时钟信号
bool clk = 0;

// 随机数生成器
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<uint8_t> data_dist(0, 255);

// 步进并转储波形函数，包含回环连接和时钟切换
void step_and_dump_wave() {
    // 切换时钟
    clk = !clk;
    top->clk = clk;
    // 设置回环连接：将 uart_txd 连接到 uart_rxd
    top->uart_rxd = top->uart_txd;
    // 评估设计
    top->eval();
    // 转储波形
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

// 初始化仿真
void sim_init() {
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    top = new VTJUT_UART_CTRL;
    contextp->traceEverOn(true);
    top->trace(tfp, 0);
    tfp->open("TJUT_UART_CTRL.vcd");

    // 初始化信号
    top->clk = 0;
    top->rstn = 0;
    top->mc_ctrl_sig = 0;
    top->ex_out_data = 0;
    top->src2 = 0;
    top->uart_rxd = 1; // UART 空闲状态为高电平

    // 应用复位
    for (int i = 0; i < 100; i++) {
        step_and_dump_wave();
    }
    top->rstn = 1;
    for (int i = 0; i < 100; i++) {
        step_and_dump_wave();
    }
}

// 结束仿真
void sim_exit() {
    step_and_dump_wave();
    tfp->close();
}

// 运行单个测试
bool run_test(uint8_t test_data) {
    // 写入数据到缓存
    top->ex_out_data = 0xFE;
    top->mc_ctrl_sig = 2; // 设置 mc_ctrl_sig[1] = 1, [0] = 0
    top->src2 = test_data;

    // 等待时钟边沿确保写入（约10个时钟周期）
    for (int i = 0; i < 10; i++) {
        step_and_dump_wave();
    }

    // 等待发送开始（uart_txd 变低，起始位）
    int wait_count = 0;
    while (top->uart_txd == 1 && wait_count < 1000) {
        step_and_dump_wave();
        wait_count++;
    }
    if (top->uart_txd == 1) {
        cout << "Error: uart_txd did not start transmission (remain high)" << endl;
        return false;
    }

    // 等待传输完成（约 4340 个时钟周期，8680 时间单位）
    for (int i = 0; i < 8680; i++) {
        step_and_dump_wave();
    }

    // 设置读取 memuartdata 的条件
    top->ex_out_data = 0xFE;
    top->mc_ctrl_sig = 1; // 设置 mc_ctrl_sig[0] = 1, [1] = 0

    // 等待一个时钟周期让 memuartdata 更新（约20个时间单位对应10个时钟周期）
    for (int i = 0; i < 20; i++) {
        step_and_dump_wave();
    }

    // 检查接收到的数据
    uint8_t received_data = top->memuartdata;
    bool pass = (received_data == test_data);

    cout << "Test data: 0x" << hex << (int)test_data << ", received: 0x" << (int)received_data << " - " << (pass ? "PASS" : "FAIL") << endl;

    return pass;
}

// 运行边界情况测试
void run_corner_case_tests() {
    cout << "\nRunning corner case tests..." << endl;
    cout << "==================================" << endl;

    run_test(0x00); // 最小值
    run_test(0xFF); // 最大值
    run_test(0x55); // 交替位模式
    run_test(0xAA); // 交替位模式
}

int main() {
    sim_init();

    int total_tests = 100; // 随机测试数量
    int passed_tests = 0;

    cout << "Starting " << total_tests << " random tests..." << endl;
    cout << "==================================" << endl;

    run_corner_case_tests();

    for (int i = 0; i < total_tests; i++) {
        uint8_t data = data_dist(gen);
        if (run_test(data)) {
            passed_tests++;
        }
    }

    cout << "==================================" << endl;
    cout << "Test Summary: " << passed_tests << "/" << total_tests << " tests passed (" << (passed_tests * 100.0 / total_tests) << "%)" << endl;

    if (passed_tests != total_tests) {
        cout << "WARNING: Some tests failed!" << endl;
    } else {
        cout << "All tests passed successfully!" << endl;
    }

    sim_exit();

    return (passed_tests == total_tests) ? 0 : 1;
}
