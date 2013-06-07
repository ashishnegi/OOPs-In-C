#ifdef SET0_C

#include "Set.h"
#if ! defined HeapSize || HeapSize < 1
#define HeapSize 20
#endif

static int Heap[HeapSize];

const void *Set;
const void *Object;

void * add(void *_set, const void *_element)
{
	int *set = (int *)_set;
	const int *element = _element;
	
	//assert((*element > Heap) && (*element < (Heap + HeapSize)));
	if(*element == HeapSize)
	{
		*(int *)element = set - Heap;
	}
	else
	{
		//assert(*element == *set);
	}
	return (void *) element;
}

void * drop(void *_set, const void *_element)
{
	int *element;

	//TODO: If i am changing it 0 here then what would delete do.
	if(element = find(_set, _element))
	{
		*element = HeapSize;
	}
	
	//TODO: what to return here.
	return (void *) element;
}

void * find(const void *_set, const void *_element)
{
	const int *set = (int *)_set;
	const int *element = _element;
	//assert((*element > 0) && (*element < HeapSize));
	
	if(*element == (set - Heap))
	{
		return (void *) element;
	}
	return 0;
}

int contains(const void *set, const void *element)
{
	return (find(set, element) != 0);
}

void * new(void *type, ...)
{
	int *p;
	for(p=Heap+1; p<(Heap + HeapSize); ++p)
	{
		if(!(*p))
			break;
	}	
	//assert(p < (Heap + HeapSize));
	*p = HeapSize;
	return (void *)(p);
}

void delete(void *_item)
{
	int *item = _item;	
	if(item)
	{
		//assert((item < HeapSize) && (item > 0));
		Heap[*item] = 0;
	}
}

int compare(void *a, void *b)
{
	return (a == b);
}

#endif