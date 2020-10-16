#include<stdio.h>
int main()
{
	//1.break语句：跳出语句，只能用于循环，switch,只跳出跟他最近的一层
	int i = 0;
	while (i < 10) 
	{
		int j = 0;
		while (j < 20)
		{
			if (i == 4)
				break;//跳出循环
			j++;
		}
		printf("i=%d,j=%d\n", i, j);
		i++;
	}
	//2.continue语句，结束当前循环，开启下一次循环
	i = 0;
	while (i < 10)
	{
		if (i % 2 == 0)
		{
			printf("偶数：i=%d\n",i);
			i++;
			continue;
		}
		printf("奇数：i=%d\n", i);
		i++;
	}
	//go to语句，尽量少用
//	int a = 0, b = 10;
//AAA:	
//	printf("hello world\n");
//	goto AAA;//循环打印

	return 0;
}