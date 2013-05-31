#include <sys/types.h>
#include "apue.h"
#include <netdb.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <time.h>

int main(void)
{
    int sockfd;
    struct stat sb;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_quit("socket error: %s", strerror(errno));
    if (fstat(sockfd, &sb) < 0)
        err_quit("fstat error: %s", strerror(errno));
    
    printf("members of sockfd.stat:\n");
    printf("st_dev: %d, %d\n", major(sb.st_dev), minor(sb.st_dev));
    printf("st_ino: %ld\n", (long int)sb.st_ino);
    printf("st_mode: %lo (octal)\n", (unsigned long)sb.st_mode);
    printf("st_uid: %ld, st_gid: %ld\n", (long)sb.st_uid, (long)sb.st_gid);
    printf("st_blksize: %ld bytes\n", (long)sb.st_blksize);
    printf("st_size: %lld bytpes\n", (long long)sb.st_size);
    printf("st_blocks: %lld\n", (long long)sb.st_blocks);
    printf("st_ctime: %s", ctime(&sb.st_ctime));
    printf("st_actime: %s", ctime(&sb.st_atime));
    printf("st_mtime: %s", ctime(&sb.st_mtime));

    exit(0);
}
