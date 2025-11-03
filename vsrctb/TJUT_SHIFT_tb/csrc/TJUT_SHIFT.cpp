#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VTJUT_SHIFT.h"
#include <iostream>
#include <random>
#include <cassert>

using namespace std;

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static VTJUT_SHIFT* top;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<uint8_t> data_dist(0, 255);
std::uniform_int_distribution<uint8_t> shift_dist(0, 7);  // 0-7位移位
std::uniform_int_distribution<uint8_t> dir_dist(0, 1);    // 移位方向
std::uniform_int_distribution<uint8_t> signed_dist(0, 1); // 有符号标志

void step_and_dump_wave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void sim_init() {
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    top = new VTJUT_SHIFT;
    contextp->traceEverOn(true);
    top->trace(tfp, 0);
    tfp->open("TJUT_SHIFT.vcd");
}

void sim_exit() {
    step_and_dump_wave();
    tfp->close();
    delete top;
    delete tfp;
    delete contextp;
}

// 计算期望的移位结果
uint8_t calculate_expected(uint8_t data, uint8_t shift_num, uint8_t dir, uint8_t is_signed) {
    if (dir == 0) {
        // 左移 - 逻辑左移，低位补0
        return data << shift_num;
    } else {
        // 右移
        if (is_signed) {
            // 算术右移 - 高位补符号位
            int8_t signed_data = static_cast<int8_t>(data);
            return static_cast<uint8_t>(signed_data >> shift_num);
        } else {
            // 逻辑右移 - 高位补0
            return data >> shift_num;
        }
    }
}

// 运行单个随机测试
bool run_random_test(int test_num) {
    uint8_t data = data_dist(gen);
    uint8_t shift_num = shift_dist(gen);
    uint8_t dir = dir_dist(gen);
    uint8_t is_signed = signed_dist(gen);
    
    top->sft_data = data;
    top->sft_num = shift_num;
    top->sft_dir = dir;
    top->is_signed = is_signed;
    
    uint8_t expected = calculate_expected(data, shift_num, dir, is_signed);
    
    step_and_dump_wave();
    
    uint8_t actual = top->sft_result;
    
    bool pass = (expected == actual);
    
    cout << "Test " << test_num << ": ";
    cout << "data=0x" << hex << (int)data;
    cout << ", shift_num=" << dec << (int)shift_num;
    cout << ", dir=" << (dir ? "RIGHT" : "LEFT");
    cout << ", signed=" << (is_signed ? "YES" : "NO");
    cout << ", expected=0x" << hex << (int)expected;
    cout << ", actual=0x" << hex << (int)actual;
    cout << " - " << (pass ? "PASS" : "FAIL") << endl;
    
    return pass;
}

// 运行边界值测试
void run_corner_case_tests() {
    cout << "\nRunning corner case tests..." << endl;
    cout << "==========================================" << endl;
    
    // 测试用例1: 左移最大值
    top->sft_data = 0xFF;
    top->sft_num = 1;
    top->sft_dir = 0; // 左移
    top->is_signed = 0;
    step_and_dump_wave();
    uint8_t expected = calculate_expected(0xFF, 1, 0, 0);
    uint8_t actual = top->sft_result;
    cout << "Corner Test 1 (LEFT SHIFT MAX by 1): ";
    cout << "expected=0x" << hex << (int)expected;
    cout << ", actual=0x" << (int)actual;
    cout << " - " << (expected == actual ? "PASS" : "FAIL") << endl;
    
    // 测试用例2: 右移有符号负数
    top->sft_data = 0x80; // -128
    top->sft_num = 1;
    top->sft_dir = 1; // 右移
    top->is_signed = 1; // 有符号
    step_and_dump_wave();
    expected = calculate_expected(0x80, 1, 1, 1);
    actual = top->sft_result;
    cout << "Corner Test 2 (ARITH RIGHT SHIFT -128 by 1): ";
    cout << "expected=0x" << hex << (int)expected;
    cout << ", actual=0x" << (int)actual;
    cout << " - " << (expected == actual ? "PASS" : "FAIL") << endl;
    
    // 测试用例3: 不移位
    top->sft_data = 0x55;
    top->sft_num = 0;
    top->sft_dir = 0;
    top->is_signed = 0;
    step_and_dump_wave();
    expected = calculate_expected(0x55, 0, 0, 0);
    actual = top->sft_result;
    cout << "Corner Test 3 (NO SHIFT): ";
    cout << "expected=0x" << hex << (int)expected;
    cout << ", actual=0x" << (int)actual;
    cout << " - " << (expected == actual ? "PASS" : "FAIL") << endl;
    
    // 测试用例4: 最大移位
    top->sft_data = 0x81;
    top->sft_num = 7;
    top->sft_dir = 1; // 右移
    top->is_signed = 1; // 有符号
    step_and_dump_wave();
    expected = calculate_expected(0x81, 7, 1, 1);
    actual = top->sft_result;
    cout << "Corner Test 4 (MAX ARITH RIGHT SHIFT): ";
    cout << "expected=0x" << hex << (int)expected;
    cout << ", actual=0x" << (int)actual;
    cout << " - " << (expected == actual ? "PASS" : "FAIL") << endl;
    
    // 测试用例5: 逻辑右移正数
    top->sft_data = 0x55;
    top->sft_num = 2;
    top->sft_dir = 1; // 右移
    top->is_signed = 0; // 无符号
    step_and_dump_wave();
    expected = calculate_expected(0x55, 2, 1, 0);
    actual = top->sft_result;
    cout << "Corner Test 5 (LOGIC RIGHT SHIFT): ";
    cout << "expected=0x" << hex << (int)expected;
    cout << ", actual=0x" << (int)actual;
    cout << " - " << (expected == actual ? "PASS" : "FAIL") << endl;
}

int main() {
    sim_init();
    
    int total_tests = 5000;
    int passed_tests = 0;
    
    cout << "Starting " << total_tests << " random tests..." << endl;
    cout << "==========================================" << endl;
    
    // 先运行边界值测试
    run_corner_case_tests();
    
    cout << "\nStarting random tests..." << endl;
    cout << "==========================================" << endl;
    
    // 运行随机测试
    for (int i = 0; i < total_tests; i++) {
        if (run_random_test(i + 1)) {
            passed_tests++;
        }
    }
    
    // 输出测试总结
    cout << "==========================================" << endl;
    cout << "Test Summary: " << passed_tests << "/" << total_tests;
    cout << " tests passed (" << (passed_tests * 100.0 / total_tests) << "%)" << endl;
    
    if (passed_tests < total_tests) {
        cout << "WARNING: Some tests failed!" << endl;
    } else {
        cout << "All tests passed successfully!" << endl;
    }
    
    sim_exit();
    
    return (passed_tests == total_tests) ? 0 : 1;
}
