#include "types.h"
#include "user.h"

#define PROCS_NUM 5


int main()
{
    printf(1, "foo started.\n");
    int pid;
    for(int i = 0; i < PROCS_NUM; i++) {
        pid = fork();
        if (pid > 0) {
            continue;
        }
        if (pid == 0) {
            int x;
            sleep(10000);
            for (long k = 0; k < 100000000000; k++) {
                x++;
            }
            exit();
        }
    }
    for(int i = 0; i < PROCS_NUM; i++) {
        wait();
    }
    printf(1, "foo finished.\n");
    exit();
}