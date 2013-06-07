#include <stdlib.h>
#include <assert.h>
#include "Set.h"

struct Set
{
	unsigned count;
};

struct Object
{
	unsigned count;
	struct Set * in;
};

#define size_t unsigned int

static const size_t _Set = sizeof(struct Set);
static const size_t _Object = sizeof(struct Object);

const void *Set = & _Set;
const void *Object = & _Object;

void * new(void *_type, ...)
{
	const size_t type = *(const size_t *) _type;
	void * p = calloc(1,type);
	char *cp = p;
	unsigned int i;
	for(i=0;i<type;++i)
	{
		cp[i] = 0;
	}
	assert(p);
	return p;
}

void delete(void *_item)
{
	free(_item);
	// no use as _item is a copy of pointer not the actual pointer.
	_item = 0;
}

void * add(void *_set, const void *_element)
{
	struct Set *set = _set;
	struct Object *element = (void *) _element;
	assert(set);
	assert(element);
	
	if(! element->in)
	{
		element->in = set;
	}
	else
	{
		assert(element->in == set);
	}

	++ (set->count);
	++ (element->count);
	return (void *) element;
}

void * drop(void *_set, void *_element)
{
	struct Set *set = _set;
	struct Object *element = find(set, _element);
	assert(set);
	
	if(element)
	{
		-- (element->count);
		-- (set->count);
		if(!element->count)
		{
			element->in = 0;
		}
	}
	
	return (void *) element;
}

void * find(const void *_set, const void *_element)
{
	const struct Set *set = _set;
	const struct Object *element = _element;
	assert(set);
	assert(element);

	if(element->in == set)
	{
		return (void *)element;
	}

	return 0;
}

int compare(void *a, void *b)
{
	return (a == b);
}

int contains(void *_set, void *_element)
{
	return (find(_set, _element) != 0);
}

int getCount(const void *_item)
{
	const struct Set *set = _item;
	assert(set);
	return set->count;
}