#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Type.h"
#include "String.h"
#include "Alloc.h"

static void * String_constructor(void * _self, va_list * arg)
{
	struct String * self = _self;
	const char * data;
	int len = 0;
	
	assert(self);
	data = va_arg(*arg, const char *);

	len = strlen(data)+1;
	self->data = (char *) malloc(len*sizeof(char));
	assert(self->data);

	strcpy_s(self->data, len, data);
	return self;
}

static void * String_destructor(void * _self)
{
	struct String * self = _self;
	assert(self);

	free(self->data);
	self->data = NULL;
	return self;
}

static void * String_clone(void const * _self)
{
	struct String const * self = _self;
	return new(String, self->data);
}

static int String_differ(void const * const _self, void const * const _other)
{
	struct String const * const self = _self;
	struct String const * const other = _other;

	if(self == other)
		return 0;
	
	if((!other) || (other->clas != String))
	{
		return 1;
	}

	return strcmp(self->data, other->data);
}

static struct Class const _String = {
	sizeof(struct String),
	String_constructor,
	String_destructor,
	String_clone,
	String_differ
};

void const * String = &_String;