#include <signal.h>
#include <unistd.h>

static void sig_alarm(int signo)
{
    /* nothing to do, just return to wake up the pause */
}

unsigned int sleep1(unsigned int nsecs)
{
    if (signal(SIGALRM, sig_alarm) == SIG_ERR)
        return(nsecs);
    alarm(nsecs);   /* start the timer */
    pause();        /* next caught signal wakes us up */
    return(alarm(0));   /* turn off timer, return unslept time */
}
