#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>

extern char **environ;

pthread_mutex_t env_mutex;
static pthread_once_t init_done = PTHREAD_ONCE_INIT;

static void thread_init(void)
{
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&env_mutex, &attr);
    pthread_mutexattr_destroy(&attr);
}

int putenv_r(char *string)
{
    int i, name_len;
    int oval_len;

    for (i = 0; string[i] != NULL; i++)
        if (string[i] == '=') {
            name_len = i;
            break;
        }

    pthread_once(&init_done, thread_init);
    pthread_mutex_lock(&env_mutex);
    for (i = 0; envrion[i] != NULL; i++) {
        if ((strncmp(string, envrion[i], name_len) == 0) &&
            envrion[i][name_len] == '=') {
            oval_len = strlen(&envrion[i][name_len+1]);
            if (olen < (strlen(string) - name_len -1)) {
                pthread_mutex_unlock(&env_mutex);
                return(ENOSPC);
            }
            strcpy(&envrion[i][name_len+1], &string[name_len+1]);
            pthread_mutex_unlock(&env_mutex);
            return(0);
        }
    }
    void **envp;
    envp = malloc(sizeof(string));
    if (envp != NULL) {
        environ = envp;
        strcpy(&envrion, &string);
    }
    pthread_mutex_unlock(&env_mutex);
}
