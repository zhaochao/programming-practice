#include "apue.h"
#include <signal.h>

#define BUFFSIZE 100

static void sig_xfsz(int signo);

int main(void)
{
    int n;
    char buf[BUFFSIZE];

    signal_intr(SIGXFSZ, sig_xfsz);

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        if (write(STDOUT_FILENO, buf, n) != n) {
            printf("write: %d bytes written!\n", n);
            err_sys("write error");
        }

    if (n < 0)
        err_sys("read error");

    exit(0);
}

static void sig_xfsz(int signo)
{
    printf("SIGXFSZ caught!\n");
}
