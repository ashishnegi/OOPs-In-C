#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "Type.h"

void * new(void const * _clas, ...)
{
	struct Class const * clas = _clas;
	void * allocMem;
	
	assert(clas);

	allocMem = calloc(1, clas->size);
	assert(allocMem);

	*((struct Class const **)allocMem) = clas;

	if(clas->constructor)
	{
		va_list list;
		va_start(list, _clas);
		clas->constructor(allocMem, &list);
		va_end(list);
	}

	return allocMem;
}

void delete(void * self)
{
	struct Class const * const * clas = self;
	if(self && (*clas) && (*clas)->destructor)
	{
		self = (*clas)->destructor(self);
	}
	free(self);
}

void draw(void * self)
{
	struct Class const * const * clas = self;
	assert(self && (*clas) && (*clas)->draw);

	(*clas)->draw(self);
}