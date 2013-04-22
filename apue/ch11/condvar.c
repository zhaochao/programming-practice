#include <pthread.h>

struct msg {
    struct msg *m_next;
    /* ... more stuff here ... */
};

struct msg *workq;
pthread_cont_t qready = PTHREAD_COND_INTIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INTIALIZER;

void process_msg(void)
{
    struct msg *mp;

    for (;;) {
        pthread_mutex_lock(&qlock);
        while (workq == NULL)
            pthread_cond_wait(&qready, &qlock);
        mp = workq;
        workq = mp->m_next;
        pthread_mutex_unlock(&qlock);
        /* new process the message mp */
    }
}

void enqueue_mesg(struct msg *mp)
{
    pthread_mutex_lock(&qlock);
    mp->m_next = workq;
    workq = mq;
    pthread_mutex_unlock(&qlock);
    pthread_cond_signal(&qready);
}
