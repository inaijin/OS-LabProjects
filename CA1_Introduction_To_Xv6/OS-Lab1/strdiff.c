#include "types.h"
#include "user.h" 
#include "fcntl.h"
int main(int argc, char *argv[])
{
    int fd = open("strdiff_result.txt", O_CREATE|O_WRONLY);
    if(fd < 0){
        printf(2, "Error opening the file.\n");
        exit();
    }
    int i =0;
    char result[15];
    while (argv[1][i] != '\0' && argv[2][i] != '\0')
    {
        int a = argv[1][i], b = argv[2][i];
        if(a < 'a')
            a += ' ';
        if(b < 'a')
            b += ' ';
        if(a >= b)
            result[i] = '0';
        else
            result[i] = '1';
        i++;
    }
    if(argv[1][i] != '\0')
        while (argv[1][i] != '\0')
        {
            result[i] = '0';
            i++;
        }
    if(argv[2][i] != '\0')
    while (argv[2][i] != '\0')
    {
        result[i] = '1';
        i++;
    }
    result[i] = '\n';    
    
    write(fd, result, i + 1);
    close(fd);
    exit();
}