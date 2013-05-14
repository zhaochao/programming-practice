#include "apue.h"

ssize_t read(int fd, void *ptr, size_t n)   /* Read "n" bytes from a descriptor */
{
    size_t nleft;
    ssize_t nread;

    nleft = n;
    while (nleft > 0) {
        if ((nread = read(fd, ptr, nleft)) < 0) {
            if (nleft == n)
                return(-1); /* error, return -1 */
            else
                break;
        } else if (nread == 0) {
            break;  /* EOF */
        }
        nleft -= nread;
        ptr += nread;
    }
    return(n - nleft);  /* return >= 0 */
}
