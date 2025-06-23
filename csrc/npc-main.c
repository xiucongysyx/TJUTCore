#include <common.h>

// 初始化一些东西
void init_monitor(int, char *[]);
// 进入sdb开始运行程序
void engine_start();
int is_exit_status_bad();

int main(int argc, char *argv[]) {
    init_monitor(argc, argv);
    engine_start();
    return is_exit_status_bad(); 
}
