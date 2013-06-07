//#include "Circle.h"
#include "Circle.r"
#include <stdarg.h>
#include <assert.h>
#include <stdio.h>
#include "Point.h"
#include "Type.h"

/*
	In Circle_draw()we have read point components for the circle by 
	invading the sub-class part with the ‘‘ invisible name ’’ _ .
*/
static void Circle_draw(void const * _self)
{
	struct Circle const * self = _self;
	assert(self);

	printf("\nCircle : Radius of %d units at center [ %d , %d ]", 
		self->rad, x(self), y(self));
}

static void * Circle_constructor(void * _self, va_list * list)
{
	struct Circle * self = ((struct Class const *) Point)->constructor(_self, list);
	self->rad = va_arg(*list, int);
	return self;
}

static void * Circle_destructor(void * _self)
{
	struct Circle * self = _self;
	self->rad = 0;

	self = ((struct Class const *) Point)->destructor(_self);
	return self;
}

static struct Class const _Circle = {
	sizeof(struct Circle),
	Circle_constructor,
	Circle_destructor,
	Circle_draw
};

void const * Circle = &_Circle;