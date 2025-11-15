#include <trap.h>

char sleep() {
    char *ret = "h";
    char i = 250;
    while(i != 0){
        i = i - 1;
        asm volatile("nop");
    }
    return *ret;
}

int main() {
    putch(0x88);
    putch(sleep());
    putch(sleep());
    asm volatile("lbu a2, 0xfe(zero)" ::: "a2");

    return 0;
}
