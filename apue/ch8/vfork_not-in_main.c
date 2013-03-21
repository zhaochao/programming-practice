#include "apue.h"

static void f1(void), f2(void);

int main(void)
{
    setbuf(stdout, NULL);

    f1();
    f2();

    printf("main in pid: %d, ppid is %d\n", getpid(), getppid());

    _exit(0);
}

static void f1(void)
{
    pid_t pid;

    if ((pid = vfork()) < 0)
        err_sys("fork error");

    printf("f1 in pid: %d, ppid is %d\n", getpid(), getppid());
}

static void f2(void)
{
    char buf[1000];
    int i;

    for (i = 0; i < sizeof(buf); i++)
        buf[i] = 0;

    printf("f2 in pid: %d, ppid is %d\n", getpid(), getppid());
}
