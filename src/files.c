#include "files.h"

int getFiles(struct options *opt, FILE **fin, FILE **fout)
{
	*fin = fopen(opt->finPath, "r");
	*fout = fopen(opt->foutPath, "w");
	
	if((*fin) == NULL || (*fout) == NULL)
		return -1;
	
	return 0;
}

void printFileError()
{
	puts("Not able to open file.");
}
