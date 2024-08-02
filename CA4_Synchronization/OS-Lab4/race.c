#include "types.h"
#include "user.h" 
#include "fcntl.h"
#include "syscall.h"

#define NUM_CHILD 5


int main(int argc, char *argv[]) {
    int pid;
    for(int i = 0; i < NUM_CHILD; i++) {
        pid = fork();
        if (pid == 0) {
            break;
        }
    }
    virtual_race(20);
    if (pid != 0) {
        for(int i = 0; i < NUM_CHILD; i++) {
            wait();
        }
    }   
    exit();
    return 0;
}