#ifndef HIERARCHY_OBJECT_R
#define HIERARCHY_OBJECT_R

#include <stdio.h>
#include <stdarg.h>

struct Object 
{
	struct Class * clas;
};

struct Class 
{
	const struct Object _;
	char * name;
	const struct Class * superClass;
	void *(*constructor)(void *self, va_list *list);
	void *(*destructor)(void *self);
	int (*differ)(const void *self, const void *other);
	void (*puto)(const void *self, FILE *fp);	
};

#endif