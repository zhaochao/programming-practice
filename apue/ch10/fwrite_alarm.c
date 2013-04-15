#include "apue.h"

char buff[209715200];

static void  sig_alrm(int signo);

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc != 2)
        err_quit("usage: fwrite_alarm filename");
    if ((fp = fopen(argv[1], "w")) == NULL)
        err_sys("can't open %s", argv[1]);

    signal(SIGALRM, sig_alrm);
    alarm(1);

    if (fwrite(buff, sizeof(buff), 1, fp) != 1)
        err_sys("fwrite error");
    
    if (ferror(fp))
        err_sys("write error");
    exit(0);
}

static void sig_alrm(int signo)
{
    printf("SIGALRM caught!\n");
}
