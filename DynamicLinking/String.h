#ifndef OOPS_STRING_H
#define OOPS_STRING_H

extern void  const * String;

struct String
{
	// class must be first :) you know why
	const void * clas;
	char * data;
};

#endif