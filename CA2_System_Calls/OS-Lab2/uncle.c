#include "types.h"
#include "user.h" 
#include "fcntl.h"
#include "syscall.h"
int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid==0) {
        printf(1, "I am Child 1\n");
    }
    else {
        wait();
        int pid = fork();
        if (pid==0) {
            printf(1, "I am Child 2\n");
        }
        else {
            wait();
            int pid = fork();
            if (pid==0) {
                printf(1, "I am Child 3\n");
                int pid = fork();
                if(pid==0){
                    printf(1, "I am Grand child\n");
                }
                else{
                    wait();
                    int result = get_uncle_count(pid);
                    printf(1, "number of uncles is: %d\n", result);
                }
            }
            else {
                wait();
            }
        }
    }
    exit();
}
