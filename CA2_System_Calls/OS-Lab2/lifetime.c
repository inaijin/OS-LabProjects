#include "types.h"
#include "user.h" 
#include "fcntl.h"
#include "syscall.h"
int main(int argc, char *argv[])
{
    int TICKS_PER_SECOND = 100;
    int pid = fork();
    if (pid==0) {
        sleep(TICKS_PER_SECOND * 10);
        int result = get_process_lifetime(getpid());
        printf(1, "child lifetime is: %d miliseconds\n", result * 1000 / TICKS_PER_SECOND);
        exit();
    }
    else {
        wait();
        
        int result = get_process_lifetime(getpid());
        printf(1, "parent lifetime is: %d miliseconds\n", result * 1000 / TICKS_PER_SECOND);
    }
    exit();
}
