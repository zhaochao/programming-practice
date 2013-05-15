#include "apue.h"
#include <fcntl.h>
#include <limits.h>

int main(void)
{
    int fd[2];
    int i, n;

    if (pipe(fd) < 0)
        err_sys("pipe error");
    set_fl(fd[1], O_NONBLOCK);

    /*
     * Write 1 byte at a time until pipe is full.
     */
    for(n = 0; ; n++) {
        if ((i = write(fd[1], "a", 1)) != 1) {
            printf("write ret %d, ", i);
            break;
        }
    }
    printf("pipe capacity = %d\n", n);
    printf("PIPE_BUF = %d\n", PIPE_BUF);
    exit(0);
}
