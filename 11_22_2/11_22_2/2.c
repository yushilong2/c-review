#include<stdio.h>
#include<stdlib.h>
int main()
{
	//feof();//EOF-end of file-文件结束标志
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("open file test.txt");
		return 0;
	}
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		putchar(ch);
	}
	if (ferror(pf))
	{
		printf("error\n");
	}
	else if (feof(pf))
	{
		printf("\nend of file\n");
	}
	fclose(pf);
	pf = NULL;

	//perror
	FILE* pf2 = fopen("test2.txt", "r");
	if (pf2 == NULL)
	{
		perror("open file test2.txt");
		return 0;
	}
	fclose(pf2);
	pf2 = NULL;

	return 0;
}