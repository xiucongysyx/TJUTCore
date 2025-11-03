#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VTJUT_ADDER.h"
#include <iostream>
#include <random>
#include <cassert>

using namespace std;

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static VTJUT_ADDER*top;

std::random_device rd;
std::mt19937  gen(rd());
std::uniform_int_distribution<uint8_t> data_dist(0,255);
std::uniform_int_distribution<uint8_t> op_dist(0,1);

void step_and_dump_wave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void sim_init() {
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    top = new VTJUT_ADDER;
    contextp->traceEverOn(true);
    top->trace(tfp,0);
    tfp->open("TJUT_ADDER.vcd");
}

void sim_exit() {
    step_and_dump_wave();
    tfp->close();
}

uint8_t calculate_expected(uint8_t data1, uint8_t data2, uint8_t op) {
    if (op == 0) {
        return data1 + data2;
    }
    else {
        return data1 - data2;
    }
}

bool run_random_test(int test_num) {
    uint8_t data1 = data_dist(gen);
    uint8_t data2 = data_dist(gen);
    uint8_t op = op_dist(gen);

    top->add_data1 = data1;
    top->add_data2 = data2;
    top->adder_sub = op;

    uint8_t expected = calculate_expected(data1, data2, op);

    step_and_dump_wave();

    uint8_t actual = top->adder_out;

    bool pass = ( expected == actual);

   std::cout << "Test " << test_num << ": ";
   std::cout << "data1=0x"  << (int)data1; 
   std::cout << ", data2=0x" << (int)data2;
   std::cout << ", op=" << (op ? "SUB" : "ADD");
   std::cout << ", expected=0x" << (int)expected;
   std::cout << ", actual=0x" << (int)actual;
   std::cout << " - " << (pass ? "PASS" : "FAIL") << std::endl;

   return pass;
}

void run_corner_case_tests() {
    std::cout << "\nRunning corner case tests..." << std::endl;
    std::cout << "==================================" << std::endl;

    top->add_data1 = 0xFF;
    top->add_data2 = 0xFF;
    top->adder_sub = 0;
    step_and_dump_wave();
    uint8_t expected = calculate_expected(0xFF, 0xFF, 0);
    uint8_t actual = top->adder_out;
    std::cout << "Corner Test 1 (MAX+MAX): expected=0x" << (int)expected;
    std::cout << ", actual=0x" <<(int)actual;
    std::cout << " - " << (expected == actual ? "PASS" : "FAIL") << std::endl;

    top->add_data1 = 0x00;
    top->add_data2 = 0x00;
    top->adder_sub = 0;
    step_and_dump_wave();
    expected = calculate_expected(0x00, 0x00, 0);
    actual = top->adder_out;
    std::cout << "Corner Test 2 (MIN+MIN): expected=0x" << (int)expected;
    std::cout << ", actual=0x" <<(int)actual;
    std::cout << " - " << (expected == actual ? "PASS" : "FAIL") << std::endl;

    top->add_data1 = 0x10;
    top->add_data2 = 0x20;
    top->adder_sub = 1;
    step_and_dump_wave();
    expected = calculate_expected(0x10, 0x20, 1);
    actual = top->adder_out;
    std::cout << "Corner Test 3 (SUB with borrow): expected=0x" << (int)expected;
    std::cout << ", actual=0x" <<(int)actual;
    std::cout << " - " << (expected == actual ? "PASS" : "FAIL") << std::endl;

    top->add_data1 = 0x50;
    top->add_data2 = 0x50;
    top->adder_sub = 1;
    step_and_dump_wave();
    expected = calculate_expected(0x50, 0x50, 1);
    actual = top->adder_out;
    std::cout << "Corner Test 3 (SUB zero): expected=0x"  << (int)expected;
    std::cout << ", actual=0x" <<(int)actual;
    std::cout << " - " << (expected == actual ? "PASS" : "FAIL") << std::endl;
}

int main() {
    sim_init();
    int total_tests = 5000;
    int passed_tests = 0;

    std::cout << "Starting " << total_tests << " random tests... " << std::endl;
    std::cout << "==================================" << std::endl;

    run_corner_case_tests();
    
    for (int i = 0; i < total_tests; i++) {
        if (run_random_test(i + 1))  {
            passed_tests++;
        }
    }

    std::cout << "==================================" << std::endl;
    std::cout << "Test Summary:  " << passed_tests << "/" << total_tests ;
    std::cout << " tests passed (" << (passed_tests * 100.0 / total_tests) << "%)" << std::endl;

    if (passed_tests != total_tests) {
        std::cout << "WARNING: Some tests failed!" << std::endl;
    } else {
        std::cout << "All tests passed successfully!" << std::endl;
    }

    sim_exit();

    return (passed_tests == total_tests) ? 0 : 1;   
}
