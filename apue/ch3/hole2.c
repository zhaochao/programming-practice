#include "apue.h"
#include <fcntl.h>

int main(void)
{
    char *filename = "file.hole2";

    char *str1 = "abcdefghij";
    char *str2 = "ABCDEFGHIJ";


    int fd;
    if ((fd = open(filename, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
        err_sys("open() failed!");

    if (write(fd, str1, strlen(str1)) != strlen(str1))
        err_sys("write() for str1 failed!");

    /*if (lseek(fd, 32, SEEK_SET) == -1)*/
    if (lseek(fd, 22, SEEK_CUR) == -1)
        err_sys("lseek() failed!");

    if (write(fd, str2, strlen(str2)) != strlen(str2))
        err_sys("write() for str2 failed!");
    else
        printf("%s created successfully!\n", filename);
}
