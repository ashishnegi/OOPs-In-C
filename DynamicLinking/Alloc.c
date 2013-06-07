#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Type.h"

void * new (void const * type, ...)
{
	// Typecast this to clas so as to get the size	
	const struct Class * clas = type;
	void * allocMem ;

	assert(clas != NULL);
	
	allocMem = calloc(1, clas->size);
	assert(allocMem != NULL);

	// Put this class into allocMem for future reference.
	*(const struct Class **)allocMem = clas;
	
	if(clas->constructor)
	{
		va_list arg;
		va_start(arg, type);

		allocMem = clas->constructor(allocMem, &arg);

		va_end(arg);
	}

	return allocMem;
}

void delete(void * self)
{
	// Run its destructor before freeing
	const struct Class ** clas = self;
	//*clas = NULL;
	//TODO: i am not going to do it like book unless i know the reason ?
	if(self && (*clas) && (*clas)->destructor)
	{
		self = (*clas)->destructor(self);
	}

	free(self);
}

/*
differ()illustrates why this technique of calling functions is called
dynamic linkage or late binding : while we can call differ()for arbitrary objects as
long as they start with an appropriate type description pointer, the function that
actually does the work is determined as late as possible—only during execution of
the actual call, not before.

differ()a selector function. It is an example of a polymorphic func-tion , 
i.e., a function that can accept arguments of different types and act differently
on them based on their types. Once we implement more classes which all contain
.differ in their type descriptors, differ()is a generic functionwhich can be applied to
any object in these classes
*/

int differ(const void *self, const void *other)
{
	const struct Class **clas = self;
	assert(self && *clas && (*clas)->differ);
	return (*clas)->differ(self, other);
}

size_t sizeOf(void const * const self)
{
	struct Class const * const * clas = self;
	assert(self && (*clas));
	return (*clas)->size;
}

void * clone(void const * self)
{
	struct Class const * const * clas = self;
	assert(self && (*clas));
	return (*clas)->clone(self);
}