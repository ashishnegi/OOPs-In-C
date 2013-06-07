#include <stdio.h>
#include "String.h"
#include "Alloc.h"



int main()
{
	void * a = new(String, "abc");
	void * aa = clone(a);
	void * b = new(String, "abe");

	printf("\nsizeof = %d sizeOf() = %d", sizeof(a), sizeOf(a));
	if(!differ(a,b))
	{
		printf("\na and b are same");
	}
	else
	{
		printf("\na and b are not same");
	}

	if(!differ(a,aa))
	{
		printf("\na and aa are same");
	}
	else
	{
		printf("\na and aa are not same");
	}

	if(!differ(aa,b))
	{
		printf("\naa and b are same");
	}
	else
	{
		printf("\naa and b are not same");
	}

	if(a == aa)
	{
		printf("\nNot a clone [a and aa]");
	}
	else
	{
		printf("\nYup Clone !!! [a and aa]");
	}

	delete(b);
	delete(aa);
	delete(a);
}