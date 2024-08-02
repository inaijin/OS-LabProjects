#include "types.h"
#include "user.h" 
#include "fcntl.h"
#include "syscall.h"

#define NUM_CHILD 5


int main(int argc, char *argv[]) {
    int pid, fd;
    rst_nsyscalls();
    for(int i = 0; i < NUM_CHILD; i++) {
        pid = fork();
        if (pid == 0) {
            break;
        }
    }
    if(pid == 0) {
        fd = open("output.txt", O_WRONLY | O_CREATE);
        if (fd < 0) {
            printf(1, "Error opening file.\n");
            exit();
        }

        char buffer[] = "Hello, Mehdi!";
        int bytes_written = write(fd, buffer, sizeof(buffer));
        if(bytes_written < 0) {
            printf(1, "Error writing to file.\n");
            exit();
        }
        close(fd);
    }
    if (pid != 0) {
        for(int i = 0; i < NUM_CHILD; i++) {
            wait();
        }
        print_nsyscalls();
    }   
    exit();
    return 0;
}