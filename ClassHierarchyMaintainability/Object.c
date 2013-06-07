#include <stdio.h>
#include <stdlib.h>
#include "Object.r"

void * new(const void *_self, ...)
{
	return malloc(sizeof(struct Object));
}

static void * Object_constructor(void *_self, va_list *list)
{
	return _self;
}

static void * Object_destructor(void *_self, va_list *list)
{
	return _self;
}

static int Object_differ(const void *_self, const void *other)
{
	return (_self == other);
}

static int Object_puto(const void *_self, FILE *fp)
{
	const struct Class * clas = classOf(_self);
	return fprintf(fp, "\nObject:\n\tName: %s\n\tMemory: %p", clas->name, _self);
}

