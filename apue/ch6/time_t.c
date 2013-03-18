#include <limits.h>
#include <time.h>
#include "apue.h"

int main(void)
{
    time_t cur_time;
    cur_time=time(NULL);

    time_t max_time = LONG_MAX;
    time_t wrap_time = max_time + 1;

    printf("Cur time: cur_time=0x%08x\n", cur_time);
    printf("    Local: %s", asctime(localtime(&cur_time)));
    printf("    GMT:   %s", asctime(gmtime(&cur_time)));
    printf("Max time: max_time=0x%08x\n", max_time);
    printf("    Local: %s", asctime(localtime(&max_time)));
    printf("    GMT:   %s", asctime(gmtime(&max_time)));
    printf("Wrap time: wrap_time=0x%08x\n", wrap_time);
    printf("    Local: %s", asctime(localtime(&wrap_time)));
    printf("    GMT:   %s", asctime(gmtime(&wrap_time)));
}
