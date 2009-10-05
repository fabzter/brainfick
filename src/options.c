#include "options.h"

void printUsage()
{
	puts("Ussage:\nbrainfick [infile] -[option] [value]");
}

int parseOptions(int argc, char **argv, struct options *opt)
{
	int i, j, tempIt;
	int isInFileFound = 0;
	char tempText[500];
	
	opt->arraySize = 30000;
	opt->foutPath = 0;
	opt->finPath = 0;
	
	for(i = 1; i < argc; i++)
	{
		for(j = 0; j < strlen(argv[i]); j++)
		{
			if(argv[i][j] == '-')
			{
				j++;
				if(j >= strlen(argv[i]) ) return -1;
				
				/*Procesamiento de las opciones disponibles */
				if(argv[i][j] == 's')
				{
					if(strlen(argv[i]) == 2)
					{
						i++;
						if(i >= argc) return -1;
						
						opt->arraySize = atoi(argv[i]);
					}
					else
					{
						for(j++, tempIt = 0; j < strlen(argv[i]); j++, tempIt++)
						{
							tempText[tempIt] = argv[i][j];
						}
						tempText[tempIt] = '\0';
						
						opt->arraySize = atoi(tempText);
					}
					
					break;
				}
				
				else if(argv[i][j] == 'o')
				{
					if(strlen(argv[i]) == 2)
					{
						i++;
						if(i >= argc) return -1;
						
						opt->foutPath = argv[i];
					}
					else
					{
						opt->foutPath = (char*)malloc(500);
						for(j++, tempIt = 0; j < strlen(argv[i]); j++, tempIt++)
						{
							tempText[tempIt] = argv[i][j];
						}
						tempText[tempIt] = '\0';
						
						strncpy(opt->foutPath, tempText, 500);
					}
					break;
				}
			}
			
			else
			{
				if(isInFileFound)
					return -1;
				
				opt->finPath = argv[i];
			}
		}
	}
	
	/*Defaults*/
	if(opt->foutPath == 0)
	{
		opt->foutPath = (char*)malloc(50);
		strncpy(opt->foutPath, "out.c", 50);
	}
	if(opt->finPath == 0)
	{
		return -1;
	}
	return 0;
}
