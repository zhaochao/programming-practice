#include "apue.h"
#include <errno.h>
#include <limits.h>
#include <sys/resource.h>

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmx = 0;
#endif

/*
 * If OPEN_MAX is indeterminate, we're not
 * guaranteed that this is adequate.
 */
#define OPEN_MAX_GUESS 256

long open_max(void)
{
    struct rlimit rl;

    if (openmax == 0) {     /* first time through */
        errno = 0;
        if ((openmax = sysconf(_SC_OPEN_MAX)) < 0 ||
             openmax == LONG_MAX) {
            if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
                err_sys("can't get open file limit");
            if (rl.rlim_max == RLIM_INFINITY)
                openmax = OPEN_MAX_GUESS;
            else
                openmax = rl.rlim_max;
        }
    }

    return openmax;
}
