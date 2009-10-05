#ifndef _TRANSLATION_H_
#define _TRANSLATION_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "options.h"

int translate(FILE *fin, FILE *fout, struct options *opt);

void writeHeaders(FILE *fout, struct options *opt);
void writeFooters(FILE *fout, struct options *opt);

void printTranslationError();

#endif
