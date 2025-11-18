#include <trap.h>
int main() {
    // 测试GPIO1输出功能
    // 设置GPIO1方向为输出 (0xfc = 方向寄存器地址)
    *((volatile char*)0xfc) = 0xFF;  // 所有引脚设为输出
    *((volatile char*)0xfd) = 'h';  // 输出10101010

    *((volatile char*)0xf9) = 0xFF;  // 所有引脚设为输出
    *((volatile char*)0xfa) = 'l';  // 输出10101010
                                     //
    char read_data1 = *((volatile char*)0xfb);
    char read_data2 = *((volatile char*)0xf8);

    char read_data3 = *((volatile char*)0xfc);
    char read_data4 = *((volatile char*)0xf9);

                                     //
    // 读取GPIO1数据寄存器验证 (0xf9 = 数据寄存器读地址)
    putch(read_data1);
    putch(read_data2);
    putch(read_data3 & 0x4f);
    putch(read_data4 & 0x4f);
    while(1);
    return 0;
}
