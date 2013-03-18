#include <sys/utsname.h>
#include "apue.h"

int main(void)
{
    struct utsname uname_buf;

    if (uname(&uname_buf) != 0)
        err_sys("uname error");

    printf("uname.sysname is %s\n", uname_buf.sysname);
    printf("uname.nodename is %s\n", uname_buf.nodename);
    printf("uname.release is %s\n", uname_buf.release);
    printf("uname.version is %s\n", uname_buf.version);
    printf("uname.machine is %s\n", uname_buf.machine);
#ifdef _GNU_SOURCE
    printf("uname.domainname is %s\n", uname_buf.domainname);
#endif

    exit(0);
}
