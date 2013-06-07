#include <stdio.h>
#include <stdlib.h>
#include "Object.h"

int main()
{
	void * object = new(Object);
	free(object);
}