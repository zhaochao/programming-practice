#include "apue.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int my_dup2(int oldfd, int newfd)
{
    int tempfd;  /* for testing whether fd is valid */

    if ((tempfd = dup(oldfd)) < 0) {
        errno = EBADF;
        return -1;
    } else
        close(tempfd);

    if (newfd < 0
#ifdef OPEN_MAX
        || newfd > OPEN_MAX
#endif
        ) {
        errno = EBADF;
        return -1;
    }

    if (newfd == oldfd)
        return newfd;

    if ((tempfd = dup(newfd)) >= 0) {
        close(tempfd);
        close(newfd);
    }

    int fds[newfd];  /* array to store tempfds */
    int index = 0;  /* index is the index of fds[] */
    while ((tempfd = dup(oldfd)) != newfd)
    {
        fds[index++] = tempfd;
    }

    int i;
    for(i = 0; i < index; i++)
        close(fds[i]);

    return newfd;
}

int main(void)
{
    char *filename = "test_mydup2";

    char *str1 = "abcdefghij";
    char *str2 = "ABCDEFGHIJ";

    int oldfd, newfd;

    if ((oldfd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR
                      | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
        err_sys("open() failed");

    if (write(oldfd, str1, strlen(str1)) != strlen(str1))
        err_sys("write str1 failed");
    printf("write str1 from fd %d\n", oldfd);

    newfd = 5;
    my_dup2(oldfd, newfd);

    if (write(newfd, str2, strlen(str2)) != strlen(str2))
        err_sys("write str2 failed");
    printf("write str2 from fd %d\n", newfd);

    exit(0);
}
