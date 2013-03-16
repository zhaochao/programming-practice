#include "apue.h"
#include <dirent.h>
#include <limits.h>

/* function type that is called for each filename */
typedef int Myfunc(const char *, const struct stat *, int);

static Myfunc myfunc;
static int myftw(char *, Myfunc *);
static int dopath(Myfunc *);

static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;

int main(int argc, char *argv[])
{
    int ret;

    if (argc != 2)
        err_quit("usage: ftw <starting-pathname>");
    ret = myftw(argv[1], myfunc);   /* does it all */

    ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock;
    if (ntot == 0)
        ntot = 1;   /* avoid divide by 0; print 0 for all counters */
    printf("regular files  = %7ld, %5.2f %%\n", nreg,
            nreg*100.0/ntot);
    printf("directories    = %7ld, %5.2f %%\n", ndir,
            ndir*100.0/ntot);
    printf("block special  = %7ld, %5.2f %%\n", nblk,
            nblk*100.0/ntot);
    printf("char special   = %7ld, %5.2f %%\n", nchr,
            nchr*100.0/ntot);
    printf("FIFOs          = %7ld, %5.2f %%\n", nfifo,
            nfifo*100.0/ntot);
    printf("symbolic links = %7ld, %5.2f %%\n", nslink,
            nslink*100.0/ntot);
    printf("sockets        = %7ld, %5.2f %%\n", nsock,
            nsock*100.0/ntot);

    exit(ret);
}

/*
 * Descend through the hierarchy, starting at "pathname".
 * The caller's func() is called for every file.
 */
#define FTW_F   1   /* file other than directory */
#define FTW_D   2   /* directory */
#define FTW_DNR 3   /* directory that can't be read */
#define FTW_NS  4   /* file that we can't stat */
#define FTW_DNC 5   /* directory that can't be changed to */

static char *fullpath;    /* contains all pathname for every file */
static char *relpath;     /* relative pathname after chdir */

static int myftw(char *pathname, Myfunc *func)  /* we return whatever func() returns */
{
    int len;
    fullpath = path_alloc(&len);    /* malloc's for PATH_MAX+1 bytes */
    relpath = path_alloc(&len);

    strncpy(fullpath, pathname, len);   /* protect against */
    fullpath[len-1] = 0;    /* buffer overrun */
    strcpy(relpath, fullpath);

    return(dopath(func));
}

/*
 * Descend through the hierarchy, starting at "fullpath".
 * If "fullpath" is anything other than a directory, we lstat() it,
 * call func(), and return. For a directory, we then first chdir to
 * it , set relpath properly and call ourself recursively for each
 * name in the directory.
 */
static int dopath(Myfunc* func) /* we return whatever func() returns */
{
    struct stat statbuf;
    struct dirent *dirp;
    DIR *dp;
    int ret;
    char *ptr;

    if (lstat(relpath, &statbuf) < 0)  /* stat error */
        return(func(fullpath, &statbuf, FTW_NS));
    if (S_ISDIR(statbuf.st_mode) == 0)  /* not a directory */
        return(func(fullpath, &statbuf, FTW_F));

    /*
     * It's a directory. First call func for directory,
     * then process each filename in the directory.
     */
    if ((ret = func(fullpath, &statbuf, FTW_D)) != 0)
        return ret;

    ptr = fullpath + strlen(fullpath);  /* point to end of fullpath */
    *ptr++ = '/';
    *ptr = 0;

    if (chdir(relpath) < 0)     /* can't change to directory */
        return(func(fullpath, &statbuf, FTW_DNC));;

    if ((dp = opendir(".")) == NULL)   /* can't read directory */
        return(func(fullpath, &statbuf, FTW_DNR));

    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") == 0 ||
            strcmp(dirp->d_name, "..") == 0)
            continue;   /* ignore dot and dot-dot */
        
        strcpy(ptr, dirp->d_name);  /* append name after slash */
        strcpy(relpath, dirp->d_name);  /* set relpath properly */

        if ((ret = dopath(func)) != 0)  /* recursive */
            break;  /* time to leave */
    }
    ptr[-1] = 0;    /* erase everything from slash onwards */

    chdir("..");
    if (closedir(dp) < 0)
        err_ret("can't close direcotry %s", fullpath);

    return(ret);
}

static int
myfunc(const char *pathname, const struct stat *statptr, int type)
{
    switch (type) {
    case FTW_F:
        switch (statptr->st_mode & S_IFMT) {
        case S_IFREG:   nreg++;     break;
        case S_IFBLK:   nblk++;     break;
        case S_IFCHR:   nchr++;     break;
        case S_IFIFO:   nfifo++;    break;
        case S_IFLNK:   nslink++;   break;
        case S_IFSOCK:  nsock++;    break;
        case S_IFDIR:
            err_dump("for S_IFDIR for %s", pathname);
            /* directories should have type = FTW_D */
        }
        break;

    case FTW_D:
        ndir++;
        break;

    case FTW_DNR:
        err_ret("can't read directory %s", pathname);
        break;

    case FTW_NS:
        err_ret("stat error for %s", pathname);
        break;

    case FTW_DNC:
        err_ret("can't change to directory %s", pathname);
        break;

    default:
        err_dump("unknown type %d for pathname %s", type, pathname);
    }

    return(0);
}
