#ifndef OOPS_ALLOC_H
#define OOPS_ALLOC_H

void * new(void const * type, ...);
void delete(void *type);

void * clone(void const * self);

int differ(void const * self, void const * other);

size_t sizeOf(void const * self);



#endif