#include "apue.h"
#include <dirent.h>
#include <fcntl.h>

int main(void)
{
    DIR *dp;
    int dpfd, dpfd_cloexec;
    int file_des, file_des_cloexec;

    if ((dp = opendir("/")) == NULL)
        err_sys("opendir error");
    dpfd = dirfd(dp);
    dpfd_cloexec = fcntl(dpfd, F_GETFD, 0);
    if (dpfd_cloexec & FD_CLOEXEC)
        printf("fd of DIR, close_on_exec flag is on\n");
    else
        printf("fd of DIR, close_on_exec flag is off\n");

    closedir(dp);

    if ((file_des = open("/", O_RDONLY)) == -1)
        err_sys("open() error");
    file_des_cloexec = fcntl(file_des, F_GETFD, 0);
    if (file_des_cloexec & FD_CLOEXEC)
        printf("fd by open(), close_on_exec flag is on\n");
    else
        printf("fd by open(), close_on_exec flag is off\n");

    close(file_des);

    exit(0);
}
