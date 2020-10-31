//打印九九口诀表
//要求对任意给定的1位正整数N,输出从1*1到N*N的部分口诀表
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i=1;
	while (i < n + 1)
	{
		int j = 1;
		while (j < i + 1)
		{
			printf("%d*%d=%d", j, i, j * i);
			if (i * j < 10) 
			{
				printf("  ");
			}
			else 
			{
				printf(" ");
			}
			j++;
		}
		i++;
		printf("\n");
	}

	return 0;
}