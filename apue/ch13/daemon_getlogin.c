#include "apue.h"

int main(void)
{
    FILE *fp;
    char *p;

    daemonize("daemon_getlogin");
    p = getlogin();
    fp = fopen("/tmp/daemon_getlogin.out", "w");
    if (fp != NULL) {
        if (p == NULL)
            fprintf(fp, "no login name\n");
        else
            fprintf(fp, "login name: %s\n", p);
    }
    exit(0);
}
