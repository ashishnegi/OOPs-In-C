#ifndef INHERITANCE_POINT_R
#define INHERITANCE_POINT_R

struct Point
{
	void * clas;
	int x, y;
};

#define x(p) (((struct Point const *)(p))->x)
#define y(p) (((struct Point const *)(p))->y)

#endif