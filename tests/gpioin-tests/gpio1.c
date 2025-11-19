#include <trap.h>
int main() {
    *((volatile char*)0xfc) = 0xff;  // 所有引脚设为输出
    *((volatile char*)0xf9) = 0xff;  // 所有引脚设为输出
                                   
    char read_data1 = *((volatile char*)0xfd);
    char read_data2 = *((volatile char*)0xfa);

                                     //
    putch(read_data1);
    putch(read_data2);
    while(1);
    return 0;
}
