#include "types.h"
#include "user.h" 
#include "fcntl.h"
#include "syscall.h"
int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int prev_ebx;
    asm volatile(
        "movl %%ebx, %0;" 
        "movl %1, %%ebx"
        :"=r"(prev_ebx)        /*output */
        :"r"(n)                /* input is variable n */
        :"%ebx"                /* clobbered register */      
    );

    int result = find_digital_root();
    
    printf(1, "digital root is: %d\n", result);

    asm volatile(
        "movl %0, %%ebx;"
        :
        :"r"(prev_ebx)
        :"%ebx"
    );
    exit();
}