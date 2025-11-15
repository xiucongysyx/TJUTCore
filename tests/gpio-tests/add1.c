#include <trap.h>
int main() {
    // 测试GPIO1输出功能
    // 设置GPIO1方向为输出 (0xfc = 方向寄存器地址)
    *((volatile char*)0xfc) = 0xFF;  // 所有引脚设为输出
    *((volatile char*)0xf8) = 0xFF;  // 所有引脚设为输出
    *((volatile char*)0xfd) = 0xFF;  // 所有引脚设为输出
    
    // 向GPIO1数据寄存器写入数据 (0xfd = 数据寄存器地址)
    *((volatile char*)0xfd) = 0xAA;  // 输出10101010

    
    // 读取GPIO1数据寄存器验证 (0xf9 = 数据寄存器读地址)
    char read_data = *((volatile char*)0xfd);
    
    if (read_data == 0xAA) {
        putch('Y');  // Output test passed
    } else {
        putch('F');  // Failed
    }
    
    while(1);
    return 0;
}
