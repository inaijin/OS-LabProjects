#include "types.h"
#include "user.h" 
#include "fcntl.h"
#include "syscall.h"
int main(int argc, char *argv[])
{
    if (copy_file(argv[1], argv[2]) < 0) {
        printf(1, "destination file is already existed!\n");
    }
    exit();
}
