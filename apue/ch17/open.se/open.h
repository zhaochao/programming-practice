#include "apue.h"
#include <errno.h>

#define CL_OPEN "open"  /* client's request for server */
#define CS_OPEN "/tmp/opend"

int csopen(char *, int);
