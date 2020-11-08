#include<stdio.h>
int main() 
{
	int line = 0;
	scanf("%d", &line);
	//打印上半部分
	int i = 0;
	int j = 0;
	for (i = 0;i < line;i++)
	{
		//打印空格
		for (j = 0;j < line - i;j++)
		{
			printf(" ");
		}
		//打印*
		for (j = 0;j <= i;j++)
		{
			printf("*");
			if (j < i)
				printf(" ");
		}
		printf("\n");
	}
	//打印下半部分
	for (i = 1;i < line;i++)
	{
		//打印空格
		for (j = 0;j <= i;j++)
		{
			printf(" ");
		}
		//打印*
		for (j = 0;j <line - i;j++)
		{
			printf("*");
			if (j < line - i - 1)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}