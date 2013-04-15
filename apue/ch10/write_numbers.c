#include "apue.h"
#include <fcntl.h>

int main(void) {
    pid_t pid;
    int fd;
    int i = 0;

    if ((fd = open("file.test", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR |
                    S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
       err_sys("open() error!");

    if (write(fd, &i, 1) != 1)
        err_sys("write() error!");

    TELL_WAIT();

    if ((pid = fork()) < 0)
        err_sys("fork() error!");
    else if (pid == 0) {
        i = 1;
        while (i < 100) {
            printf("child: write %d to file.\n", i);
            if (write(fd, &i, 1) != 1)
                err_sys("child: write() error!");
            i = i + 2;
            TELL_PARENT(getppid());
            WAIT_PARENT();
        }
    } else {
        while (i < 100) {
            WAIT_CHILD();
            i = i + 2;
            printf("parent: write %d to file.\n", i);
            if (write(fd, &i, 1) != 1)
                err_sys("parent: write() error!");
            TELL_CHILD(pid);
        }
    }

    return 0;
}
