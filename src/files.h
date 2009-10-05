#ifndef _FILES_H_
#define _FILES_H_

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "options.h"

int getFiles(struct options *opt, FILE **fin, FILE **fout);
void printFileError();

#endif
