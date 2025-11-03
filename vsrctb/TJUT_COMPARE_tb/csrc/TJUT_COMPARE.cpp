#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VTJUT_COMPARE.h"
#include <iostream>
#include <random>
#include <cassert>

using namespace std;

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static VTJUT_COMPARE* top;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<uint8_t> data_dist(0, 255);
std::uniform_int_distribution<uint8_t> signed_dist(0, 1);

void step_and_dump_wave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void sim_init() {
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    top = new VTJUT_COMPARE;
    contextp->traceEverOn(true);
    top->trace(tfp, 0);
    tfp->open("TJUT_COMPARE.vcd");
}

void sim_exit() {
    step_and_dump_wave();
    tfp->close();
    delete top;
    delete tfp;
    delete contextp;
}

// 计算期望的比较结果
uint8_t calculate_expected(uint8_t data1, uint8_t data2, uint8_t is_signed) {
    bool com_eq = (data1 == data2);
    bool com_lt;
    
    if (is_signed) {
        // 有符号比较
        int8_t signed_data1 = static_cast<int8_t>(data1);
        int8_t signed_data2 = static_cast<int8_t>(data2);
        com_lt = (signed_data1 < signed_data2);
    } else {
        // 无符号比较
        com_lt = (data1 < data2);
    }
    
    return (com_eq << 1) | com_lt; // {相等, 小于}
}

// 运行单个随机测试
bool run_random_test(int test_num) {
    uint8_t data1 = data_dist(gen);
    uint8_t data2 = data_dist(gen);
    uint8_t is_signed = signed_dist(gen);
    
    top->com_data1 = data1;
    top->com_data2 = data2;
    top->is_signed = is_signed;
    
    uint8_t expected = calculate_expected(data1, data2, is_signed);
    
    step_and_dump_wave();
    
    uint8_t actual = top->com_results;
    
    bool pass = (expected == actual);
    
    cout << "Test " << test_num << ": ";
    cout << "data1=0x" << hex << (int)data1;
    cout << ", data2=0x" << hex << (int)data2;
    cout << ", is_signed=" << (is_signed ? "SIGNED" : "UNSIGNED");
    cout << ", expected=0x" << hex << (int)expected;
    cout << " [EQ=" << ((expected & 2) >> 1) << ", LT=" << (expected & 1) << "]";
    cout << ", actual=0x" << hex << (int)actual;
    cout << " [EQ=" << ((actual & 2) >> 1) << ", LT=" << (actual & 1) << "]";
    cout << " - " << (pass ? "PASS" : "FAIL") << endl;
    
    return pass;
}

// 运行边界值测试
void run_corner_case_tests() {
    cout << "\nRunning corner case tests..." << endl;
    cout << "==========================================" << endl;
    
    // 测试用例1: 最大值比较（无符号）
    top->com_data1 = 0xFF;
    top->com_data2 = 0xFE;
    top->is_signed = 0;
    step_and_dump_wave();
    uint8_t expected = calculate_expected(0xFF, 0xFE, 0);
    uint8_t actual = top->com_results;
    cout << "Corner Test 1 (MAX vs MAX-1 UNSIGNED): ";
    cout << "expected=0x" << hex << (int)expected;
    cout << ", actual=0x" << (int)actual;
    cout << " - " << (expected == actual ? "PASS" : "FAIL") << endl;
    
    // 测试用例2: 有符号负数比较
    top->com_data1 = 0x80; // -128
    top->com_data2 = 0x7F; // 127
    top->is_signed = 1;
    step_and_dump_wave();
    expected = calculate_expected(0x80, 0x7F, 1);
    actual = top->com_results;
    cout << "Corner Test 2 (-128 vs 127 SIGNED): ";
    cout << "expected=0x" << hex << (int)expected;
    cout << ", actual=0x" << (int)actual;
    cout << " - " << (expected == actual ? "PASS" : "FAIL") << endl;
    
    // 测试用例3: 相等测试
    top->com_data1 = 0x55;
    top->com_data2 = 0x55;
    top->is_signed = 0;
    step_and_dump_wave();
    expected = calculate_expected(0x55, 0x55, 0);
    actual = top->com_results;
    cout << "Corner Test 3 (EQUAL UNSIGNED): ";
    cout << "expected=0x" << hex << (int)expected;
    cout << ", actual=0x" << (int)actual;
    cout << " - " << (expected == actual ? "PASS" : "FAIL") << endl;
    
    // 测试用例4: 有符号正负数边界
    top->com_data1 = 0x00; // 0
    top->com_data2 = 0xFF; // -1 (有符号)
    top->is_signed = 1;
    step_and_dump_wave();
    expected = calculate_expected(0x00, 0xFF, 1);
    actual = top->com_results;
    cout << "Corner Test 4 (0 vs -1 SIGNED): ";
    cout << "expected=0x" << hex << (int)expected;
    cout << ", actual=0x" << (int)actual;
    cout << " - " << (expected == actual ? "PASS" : "FAIL") << endl;
    
    // 测试用例5: 无符号边界
    top->com_data1 = 0x00;
    top->com_data2 = 0xFF;
    top->is_signed = 0;
    step_and_dump_wave();
    expected = calculate_expected(0x00, 0xFF, 0);
    actual = top->com_results;
    cout << "Corner Test 5 (0 vs 255 UNSIGNED): ";
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
