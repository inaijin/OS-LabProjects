#include "types.h"
#include "user.h" 
#include "fcntl.h"
#include "syscall.h"
#include "mmu.h"

#define NUM_CHILD 50


int main(int argc, char *argv[]) {
    char *addr;
    int pid, value;

    for(int i = 0; i < NUM_CHILD; i++) {
        pid = fork();
        if (pid == 0) {
            break;
        }
    }

    addr = open_sharedmem(PGSIZE, 0);

    if(pid == 0) {
        inc_sharedmem((int)addr, 0);
        sleep(100);
    }

    if (pid != 0) {
        sleep(100);
        value = getval_sharedmem((int)addr, 0);
        for(int i = 0; i < NUM_CHILD; i++) {
            wait();
        }
        printf(1, "value of sharedmem: %d\n", value);
    }  
    close_sharedmem(PGSIZE, 0);
    exit();
    return 0;
}