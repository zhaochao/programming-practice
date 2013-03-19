#include <stdio.h>

#define DATAFILE "datafile"

FILE * open_data(void)
{
    FILE *fp;
    char databuf[BUFSIZ];   /* setbuf make this the stdio buffer */

    if ((fp = fopen(DATAFILE, "r")) == NULL)
        return(NULL);
    if (setvbuf(fp, databuf, _IOLBF, BUFSIZ) != 0)
        return(NULL);
    return(fp);     /* error */
}
