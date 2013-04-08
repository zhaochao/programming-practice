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
    struct sigaction act_int, oact_int;
    struct sigaction act_quit, oact_quit;

    act_int.sa_handler = sig_int;
    sigemptyset(&act_int.sa_mask);
    act_int.sa_flags = 0;
    if (sigaction(SIGINT, &act_int, &oact_int) < 0)
        err_sys("sigaction(SIGINT) error");

    act_quit.sa_handler = sig_int;
    sigemptyset(&act_quit.sa_mask);
    act_quit.sa_flags = 0;
    if (sigaction(SIGQUIT, &act_quit, &oact_quit) < 0)
        err_sys("sigaction(SIGQUIT) error");

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

    /*
     * Reset signal action.
     */
    if (sigaction(SIGINT, &oact_int, NULL) < 0)
        err_sys("sigaction(SIGINT) reset error");
    if (sigaction(SIGQUIT, &oact_quit, NULL) < 0)
        err_sys("sigaction(SIGQUIT) reset error");

    exit(0);
}
