#include "apue.h"
#include <time.h>

int main(int argc, char *argv[])
{
    struct stat buf;

    char *ptr;

    if (argc != 2) {
        printf("usage: %s <file_name>\n", argv[0]);
        exit(-1);
    }

    if (stat(argv[1], &buf) < 0)
        err_sys("stat() failed!");

    printf("File type: ");
    switch (buf.st_mode & S_IFMT) {
    case S_IFBLK:   ptr = "block device";   break;
    case S_IFCHR:   ptr = "character device";   break;
    case S_IFDIR:   ptr = "direcotry";  break;
    case S_IFIFO:   ptr = "fifo";   break;
    case S_IFLNK:   ptr = "symlink";    break;
    case S_IFREG:   ptr = "regular file";   break;
    case S_IFSOCK:  ptr = "socket"; break;
    default:    ptr = "unknown?";   break;
    }
    printf("%s\n", ptr);

    printf("I-node number: %ld\n", (long) buf.st_ino);
    printf("Mode: %lo (octal)\n", (unsigned long) buf.st_mode);
    printf("Link count: %ld\n", (long) buf.st_nlink);
    printf("Ownership: uid=%ld gid=%ld\n", (long) buf.st_uid, (long) buf.st_gid);
    printf("Preferred I/O block size: %ld bytes\n", (long) buf.st_blksize);
    printf("File size: %lld bytes\n", (long long) buf.st_size);
    printf("Block allocated: %lld\n", (long long) buf.st_blocks);

    printf("Last status change: %s", ctime(&buf.st_ctime));
    printf("Last file access: %s", ctime(&buf.st_atime));
    printf("Last file modification: %s", ctime(&buf.st_mtime));

    exit(0);
}
