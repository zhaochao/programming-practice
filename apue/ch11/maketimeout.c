void maketimeout(struct timespec *tsp, long minutes)
{
    struct timeval now;

    gettimeofday(&now);
    tsp->tv_sec = new.tv_sec;
    tsp->tv_nsec = new.tv_usec * 1000;  /* usec to nsec */
    /* add the offset to get timeout value */
    tsp->tv_sec += minutes * 60;
}
