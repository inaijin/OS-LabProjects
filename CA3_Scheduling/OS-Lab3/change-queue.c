#include "types.h"
#include "user.h" 
#include "fcntl.h"
#include "syscall.h"
int main(int argc, char *argv[])
{
    int pid = atoi(argv[1]);
    printf(1, "%d-befor=%d\n", get_queue_number(pid));

    if( change_queue(atoi(argv[1]), atoi(argv[2]))) {
        printf(1, "Process Not found!\n");
    }
    printf(1, "after=%d\n", get_queue_number(pid));
    exit();
}