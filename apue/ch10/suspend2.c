#include "apue.h"

volatile sig_atomic_t quitflag;     /* set nonzero by signal handler */

/* one signal handler for SIGINT and SIGQUIT */
static void sig_int(int signo)
{
    if (signo == SIGINT)
        printf("\ninterrput\n");
    else if (signo == SIGQUIT)
        quitflag = 1;   /* set flag for main loop */
}

int main(void)
{
    sigset_t newmask, oldmask, zeromask;

    if (signal(SIGINT, sig_int) < 0)
        err_sys("signal(SIGNIT) error");
    if (signal(SIGQUIT, sig_int) < 0)
        err_sys("signal(SIGQUIT) error");

    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);

    /*
     * Block SIGQUIT and save current signal mask.
     */
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        err_sys("SIG_BLOCK error");

    while (quitflag == 0)
        sigsuspend(&zeromask);

    /*
     * SIGQUIT has been caught and is now blocked; do whatever.
     */
    quitflag = 0;
    
    /*
     * Reset signal mask which unblocks SIGQUIT.
     */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("SIG_SETMASK error");

    exit(0);
}
