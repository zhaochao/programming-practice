#include <signal.h>
#include <errno.h>
#include "apue.h"

void pr_mask(const char *str)
{
    sigset_t sigset;
    int errno_save;

    errno_save = errno;     /* we can be called by signal handlers */
    if (sigprocmask(0, NULL, &sigset) < 0)
        err_sys("sigprocmask error");

    printf("%s", str);

    int i = 1;
    while (sys_siglist[i]) {
        if (sigismember(&sigset, i)) printf("\"%s\" ", sys_siglist[i]);
        i++;
    }

    printf("\n");
    errno = errno_save;
}
