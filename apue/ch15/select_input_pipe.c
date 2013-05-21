#include "apue.h"
#include <sys/select.h>

int main(void)
{
    int fds[2];
    pid_t pid;
    int status;

    if (pipe(fds) < 0)
        err_sys("pipe error");

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid > 0) {   /* parent */
        close(fds[0]);
        close(fds[1]);   /* close write end of the pipe */

        if (waitpid(pid, &status, 0) < 0)
            err_sys("waitpid error");

        exit(0);
    } else {    /* child */
        close(fds[1]);
        
        fd_set rfds;
        struct timeval tv;
        int retval;

        FD_ZERO(&rfds);
        FD_SET(fds[0], &rfds);

        /* wait up to 1 second */
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        retval = select(1, &rfds, NULL, NULL, &tv);

        if (retval == -1)
            err_sys("select error");
        else if (retval)
            printf("pipe is ready to read.\n");
        else
            printf("no data within one second.\n");

        exit(0);
    }
}
