#include <time.h>
#include "apue.h"

int main(void)
{
    char outstr[MAXLINE];
    char *fmtstr = "%a %b %d %T %Z %Y";
    time_t cur_time;
    struct tm *cur_tm;

    cur_time = time(NULL);
    cur_tm = localtime(&cur_time);

    if (cur_tm == NULL)
        err_sys("localtime error");

    if (strftime(outstr, sizeof(outstr), fmtstr, cur_tm) == 0)
        err_sys("strftime error");

    printf("%s\n", outstr);
    exit(0);
}
