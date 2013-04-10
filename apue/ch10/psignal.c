#include <signal.h>
#include <stdio.h>

int main(void)
{
    psignal(SIGINT, "testing psignal(SIGINT)");

    int i = 0;
    //while (i == 0 || sys_siglist[i]) {
    while ((! i) || sys_siglist[i]) {
        printf("sys_siglist[%d] is %s.\n", i, sys_siglist[i]);
        i++;
    }
    /*
    do {
        printf("sys_siglist[%d] is %s.\n", i, sys_siglist[i]);
        i++;
    } while (sys_siglist[i]);
    */

    printf("At last, i is: %d.\n", i);

    return 0;
}
