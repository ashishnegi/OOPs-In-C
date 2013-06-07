#ifndef INHERITANCE_TYPE_H
#define INHERITANCE_TYPE_H

#define unsigned int size_t

struct Class
{
	size_t size;

	void * (* constructor) (void * self, va_list * list);

	void * (* destructor) (void * self);

	// Draw is dynamic function :)
	void (* draw) (void const * self);
};

#endif