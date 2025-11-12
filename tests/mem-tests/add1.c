#include <trap.h>

uint8_t if_else(char n) {
    char cost;
    if(n > 5) cost = 40;
    else if(n == 1) cost = 10;
    else cost = 0;
    return cost;
}

int main() {
    check(if_else(1) == 10);
    check(if_else(2) == 0);
    check(if_else(7) == 40);
    check(if_else(13) == 40);

    return 0;
}
