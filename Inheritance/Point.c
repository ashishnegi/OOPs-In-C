#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include "Type.h"
#include "Point.h"
#include "Point.r"
static void * Point_constructor(void * _self, va_list * list)
{
	struct Point * self = _self;
	assert(self);

	self->x = va_arg(*list, int);
	self->y = va_arg(*list, int);

	return self;
}

static void * Point_destructor(void * _self)
{
	struct Point * self = _self;
	assert(self);

	self->x = self->y = 0;

	return self;
}

static void Point_draw(void const * _self)
{
	struct Point const * self = _self;
	assert(self);

	printf("\nPoint \".\" at [ %d , %d ]" , self->x, self->y);
}

static const struct Class _Point = {
	sizeof(struct Point),
	Point_constructor,
	Point_destructor, // can be 0 also beacuse this is doing nothing.
	Point_draw
};

void const * Point = &_Point;

// Not a dynamic method
void move(void * _self, int dx, int dy)
{
	struct Point * self = _self;
	assert(self);

	self->x += dx;
	self->y += dy;
}
