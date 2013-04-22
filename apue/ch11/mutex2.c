#include <stdlib.h>
#include <pthread.h>

#define NHASH 29
#define HASH(fp) (((unsigned long) fp)%NHASH)
struct foo *fh[NHASH];

pthread_mutex_t hash_lock = PTHREAD_MUTEX_INITIALIZER;

struct foo {
    int f_count;
    pthread_mutex_t f_lock;
    struct foo *f_next; /* protected by hash_lock */
    int f_id;
    /* ... more stuff here ... */
};

struct foo *foo_alloc(void) /* allocate the object */
{
    struct foo *fp;
    int idx;

    if ((fp = malloc(sizeof(struct foo))) != NULL) {
        fp->f_count = 1;
        if (pthread_mutex_init(&fp->f_lock) != 0) {
            free(fp);
            return NULL;
        }
        idx = HASH(fp);
        pthread_mutex_lock(&hash_lock);
        fp->f_next = fh[idx];
        fh[idx] = fp->f_next;
        pthread_mutex_lock(&fp->f_lock);
        pthread_mutex_unlock(&hash_lock);
        /* ... continue initialization ... */
        pthread_mutex_unlock(&fp->f_lock);
    }
    return(fp);
}

void foo_hold(struct foo *fp)   /* add a referrence to the object */
{
    pthread_mutex_lock(&fp->f_lock);
    fp->f_count++;
    pthread_mutex_unlock(&fp->f_lock);
}

struct foo *foo_find(int id)    /* find an existing object */
{
    struct foo *fp;
    int idx;

    idx = HASH(fp);

    pthread_mutex_lock(&hash_lock);
    for (fp = fh[idx]; fp != NULL; fp->fp_next) {
        if (fp->f_id == id) {
            foo_hold(fp);
            break;
        }
    }
    pthread_mutex_unlock(&hash_lock);
    return(fp);
}

void foo_rele(struct foo *fp)   /* release a referrect to the object */
{
    struct foo *fp;
    int idx;

    pthread_mutex_lock(&fp->f_lock);
    if (fp->f_count == 1) { /* last referrence */
        pthread_mutex_unlock(&fp->f_lock);
        pthread_mutex_lock(&hash_lock);
        pthread_mutex_lock(&fp->f_lock);
        /* need to recheck the condition */
        if (fp->f_count != 1) {
            fp->f_count--;
            pthread_mutex_unlock(&fp->f_lock);
            pthread_mutex_unlock(&hash_lock);
            return;
        }
        /* remove from list */
        idx = HASH(fp);
        tfp = fh[idx];
        if (tfp == fp) {
            fh[idx] = fp->f_next;
        } else {
            while (tfp->f_next != fp)
                tfp = tfp->f_next;
            tfp->f_next = fp->f_next;
        }
        pthread_mutex_unlock(&hash_lock);
        pthread_mutex_unlock(&fp->f_lock);
        pthread_mutex_destroy(&fp->f_lock);
        free(fp);
    } else {
        fp->f_count--;
        pthread_mutex_unlock(&fp->f_lock);
    }
}
