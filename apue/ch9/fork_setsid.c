#include "apue.h"

/* pr_ids:
static void pr_ids(char *name)
{
    printf("%s: pid = %d, ppid = %d, sid = %d, pgrp = %d, tpgrp = %d\n",
            name, getpid(), getppid(), getsid(getpid()), getpgrp(),
            tcgetpgrp(STDIN_FILENO));
    fflush(stdout);
}
*/

#define PS_FMT "ps -o pid,ppid,pgrp,session,tpgid,tt,comm -p %d %d"

int main(void)
{
    pid_t pid;
    char ps_comm[BUFSIZ];

    TELL_WAIT();

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0) {
        pid_t sess_id;
        if ((sess_id = setsid()) == ((pid_t) -1))
            err_sys("setsid error");
        sprintf(ps_comm, PS_FMT, getpid(), getppid());
        setbuf(stdout, NULL);
        printf("child:\n");
        system(ps_comm);
        TELL_PARENT(getppid());
    } else {
        WAIT_CHILD();
        sprintf(ps_comm, PS_FMT, getpid(), getppid());
        setbuf(stdout, NULL);
        printf("parent:\n");
        system(ps_comm);
    }

    exit(0);
}
