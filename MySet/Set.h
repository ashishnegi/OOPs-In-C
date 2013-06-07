#ifndef OOPS_SET_H
#define OOPS_SET_H

// #define SET_C 1

extern const void * Set;

void * add(void *set, const void *element);
void * drop(void *set, const void *element);
void * find(const void *set, const void *element);
int contains(const void *set, const void *element);
int getCount(const void *);

#endif
