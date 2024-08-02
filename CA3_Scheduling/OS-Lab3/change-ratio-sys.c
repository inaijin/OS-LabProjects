#include "types.h"
#include "user.h" 
#include "fcntl.h"
#include "syscall.h"
int main(int argc, char *argv[])
{
    if(change_sys_ratio(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])) == -1) {
        printf(1, "Error!\n");
    }
    exit();
}