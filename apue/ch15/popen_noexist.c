#include "apue.h"

int main(void)
{
    FILE *fp;

    fp = popen("./noexist", "w");
    pclose(fp);

    exit(0);
}
