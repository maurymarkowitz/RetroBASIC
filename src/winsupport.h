
#ifndef WINSUPPORT_H
#define WINSUPPORT_H

typedef struct timeval {
    long tv_sec;
    long tv_usec;
} timeval;

struct timezone;

extern int gettimeofday(struct timeval* tp, struct timezone* tzp);
extern void timersub(struct timeval* a, struct timeval* b, struct timeval* res);
extern unsigned int sleep(unsigned int seconds);
extern void clrscr();

#endif