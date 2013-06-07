#ifndef HIERARCHY_OBJECT_H
#define HIERARCHY_OBJECT_H

#include <stdio.h>

extern const void * Object;
extern const void * Class;

void * new(void const * clas, ...);

void delete(void const * self);

void * constructor(void * self, va_list * list);

void * destructor(void * self);

int differ(const void * self, const void * b);

int puto(const void * self, FILE *fp);

#endif