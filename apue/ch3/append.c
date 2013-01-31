#include "apue.h"
#include <fcntl.h>
#include <string.h>

int main(void)
{
    char *filename = "test_appending";

    char *string1 = "abcdefghij";
    char *string2 = "ABCDEFGHIJ";

    int fd;
    off_t currpos;  /* currpos holds current offset in fd */

    if((fd = open(filename, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR |
                            S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
        err_sys("open() failed!");

    printf("fd: %d\n", fd);
    currpos = lseek(fd, 0, SEEK_CUR);
    printf("currpos: %ld\n", currpos);

    if(write(fd, string1, strlen(string1)) < 0)
        err_sys("write string1 failed!");

    currpos = lseek(fd, 0, SEEK_CUR);
    printf("after write string1, currpos: %ld\n", currpos);

    currpos = lseek(fd, 0, SEEK_SET);
    printf("setting offset to 0.\n");

    if(write(fd, string2, strlen(string2)) != strlen(string2))
        err_sys("write string2 failed!");

    currpos = lseek(fd, 0, SEEK_CUR);
    printf("after write string2, currpos: %ld\n", currpos);

    exit(0);
}
