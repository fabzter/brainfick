#include "translation.h"

int translate(FILE *fin, FILE *fout, struct options *opt)
{
//TODO: revisar primero sintaxis... :S (balance de loops?)
	char c=1;
	
	writeHeaders(fout, opt);
	
	while( (c = fgetc(fin)) != EOF )
	{
		if(c == '>')
		{
			fprintf(fout, "++ptr;");
		}
		else if(c == '<')
		{
			fprintf(fout, "--ptr;");
		}
		else if(c == '+')
		{
			fprintf(fout, "++(*ptr);");
		}
		else if(c == '-')
		{
			fprintf(fout, "--(*ptr);");
		}
		else if(c == '.')
		{
			fprintf(fout, "putchar(*ptr);");
		}
		else if(c == ',')
		{
			fprintf(fout, "*ptr = getchar();");
		}
		else if(c == '[')
		{
			fprintf(fout, "while (*ptr) {");
		}
		else if(c == ']')
		{
			fprintf(fout, "}");
		}
	}
	
	writeFooters(fout, opt);
	
	return 0;
}

void writeHeaders(FILE *fout, struct options *opt)
{
	fprintf(fout, "%s%s", "#include<stdio.h>\n#include<stdlib.h>\n", 
	"unsigned char *ptr;int main(){");
	
	fprintf(fout, "ptr=(unsigned char*)malloc(%i*sizeof(unsigned char));",
	opt->arraySize);
}

void writeFooters(FILE *fout, struct options *opt)
{
	fprintf(fout, "return 0;}");
}

void printTranslationError()
{
	printf("Error while translating your file.\n");
}
