#include <trap.h>

int add1(int a, int b) {
    char c = a + b;
    return c;
}

int main(){
    char i, j, k;
    i = 1;
    j = 2;
    k = add1(i, j);
    if(k == 3) return 0;
}
