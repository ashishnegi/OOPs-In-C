#ifndef OOPS_TYPE_H
#define OOPS_TYPE_H

#define unsigned size_t

struct Class
{
	size_t size;
	/*
		There can be anything in consructor.
		so either we pass like va_arglist or ...
		we would go with va_arg because constructor is called from new :)
	*/
	void *(* constructor) (void * self, va_list * arg);

	// I think that there is nothing for destructor to return.
	void *(* destructor)(void * self);

	void *(* clone)(const void * self);

	int (*differ)(const void *a, const void *b);
};

#endif