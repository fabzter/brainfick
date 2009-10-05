#include <stdio.h>
#include "options.h"

int main(int argc, char *argv[])
{
	/*Dewclaraciones hasta arriba solo para compatibilidad con windows :S*/
	FILE *fin, *fout;
	struct options opt;
	
	if(parseOptions(argc, argv, &opt) < 0) //checa las opcines y prende banderas
	{
		printUsage();
		return 1;
	}
	
	//printf("S = %i, fout = %s, fin = %s\n", opt.arraySize, opt.foutPath, opt.finPath);
	
	if(getFiles(&opt, &fin, &fout) < 0) //obtenemos los descriptores de archivo correspondientes
	{
		printFileError();
		return 2;
	}
	
	/*Seguimos al trabajo de verdad :D*/
	if(translate(fin, fout, &opt) < 0)
	{
		printTranslationError();
		return 3;
	}
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}
