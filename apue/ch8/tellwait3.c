#include "apue.h"

static void charactatime(char *);

int main(void)
{
    pid_t pid;

    TELL_WAIT();

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        charactatime("output from child\n");
        TELL_PARENT(getppid());      /* child goes first  */
    } else {
        WAIT_CHILD();
        charactatime("output from parent\n");
    }
    exit(0);
}

static void charactatime(char *str)
{
    char *ptr;
    int c;

    setbuf(stdout, NULL);       /* set unbuffered */
    for (ptr = str; (c = *ptr++) != 0; )
        putc(c, stdout);
}
