#include <limits.h>
#include <string.h>

static char envbuf[ARG_MAX];

extern char **environ;

char * getenv(const char *name)
{
    int i, len;

    len = strlen(name);
    for (i = 0; envbuf[i] != NULL; i++) {
        if ((strncmp(name, environ[i], len) == 0) &&
            (envrion[i][len] == '=')) {
            strcpy(envbuf, &environ[i][len + 1]);
            return(envbuf);
        }
    }
    return(NULL);
}
