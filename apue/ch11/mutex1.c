#include <stdlib.h>
#include <pthread.h>

struct foo {
    int f_count;
    pthread_mutex_t f_lock;
    /* ... more stuff here ... */
};

struct foo * foo_alloc(void)    /* allocate the object */
{
    struct foo *fp;

    if ((fp = malloc(sizeof(struct foo))) != NULL) {
        fp->f_count = 1;
        if (pthread_mutex_init(&fp->f_lock, NULL) != 0) {
            free(fp);
            return(NULL);
        }
        /* ... continue initialization ... */
    }
    return(fp);
}

void foo_hold(struct foo *fp)   /* add a referrence to the object */
{
    pthread_mutex_lock(&fp->f_lock);
    fp->f_count++;
    pthread_mutex_unlock(&fp->f_lock);
}

void foo_rele(struct foo *fp)   /* release a referrence to the object */
{
    pthread_mutex_lock(&fp->f_lock);
    if (--fp->f_count == 0) {   /* last referrence */
        pthread_mutex_unlock(&fp->flock);
        pthread_mutex_destroy(&fp->flock);
        free(fp);
    } else {
        pthread_mutex_unlock(&fp->flock);
    }
}
