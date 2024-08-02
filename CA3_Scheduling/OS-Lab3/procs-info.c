#include "types.h"
#include "user.h" 
#include "fcntl.h"
#include "syscall.h"
int main(int argc, char *argv[])
{
    print_procs_info();
    exit();
}