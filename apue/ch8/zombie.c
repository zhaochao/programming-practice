#include "apue.h"

int main(void)
{
    pid_t pid;
    char cmd[BUFSIZ];

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
        exit(0);

    sprintf(cmd, "ps -fp %d %d %d", pid, getpid(), getppid());

    setbuf(stdout, NULL);
    printf("command: %s\n", cmd);
    system(cmd);

    exit(0);
}
