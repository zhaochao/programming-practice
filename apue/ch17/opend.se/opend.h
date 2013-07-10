#include "apue.h"
#include <errno.h>

#define CL_OPEN "open"  /* client's request for server */
#define CS_OPEN "/tmp/opend"

extern char errmsg[];   /* error message string to return to client */
extern int oflag;   /* open() flag: O_xxx ... */
extern char *pathname;  /* of file to open() for client */
extern int debug;   /* nonzero if interactive (not daemon) */

typedef struct {    /* one client struct per connected client */
    int fd;     /* fd, or -1 if available */
    uid_t uid;
} Client;

extern Client *client;  /* ptr to malloc'ed array */
extern int client_size;     /* # enteries in client[] array */

int cli_args(int, char **);
void request(char *, int, int, uid_t);
int client_add(int, uid_t);
void client_del(int);
void loop(void);
