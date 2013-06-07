#include <stdio.h>
#include "New.h"
#include "Point.h"
#include "Circle.h"

int main()
{
	void * circle, * point;
	point = new(Point, 0, 19);
	draw(point);
	move(point, 19, 0);
	draw(point);
	delete(point);
	getchar();

	circle = new(Circle, 10, 10, 20);
	draw(circle);
	move(circle, 10, 5);
	draw(circle);
	delete(circle);
}