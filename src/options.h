#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include <stdlib.h>
#include<string.h>

struct options
{
	size_t arraySize;
	char* finPath;
	char* foutPath;
};

int parseOptions(int argc, char **argv, struct options *opt);
void printUsage();

#endif
