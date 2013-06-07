#include <stdio.h>
#include "New.h"
#include "Object.h"
#include "Set.h"

int main()
{
	// Set set = new Set();
	// set.add(5);

	void * set = new(Set);
	void * a = add(set, new(Object));
	void * b = add(set, new(Object));
	void * c = new(Object);
	
	// Added 2nd a in set
	add(set, a);

	if(contains(set, a))
	{
		puts("successful: a in set");
		printf("Count of a in set is %d\n", getCount(a));
	}

	if(contains(set, c))
		puts("successful: c in set");
	else
		puts("No c in set");
	
	if(find(set,a))
		puts("Found a in set");
	
	printf("Total objects in set are: %d\n", getCount(set));

	delete(drop(set, a));
	delete(drop(set,b));
	delete(drop(set,c));
	delete(set);

	puts("Deleted Every Object");
	
	if(find(set,a))
		puts("Found a in set");
	else
		puts("Could not find a in set");
}
