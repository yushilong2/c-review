//念数字
//输入一个整数，输出每个数字对应的汉字。当整数为负数时，先输出“负”字。
#include<stdio.h>
int read(int a) 
{
	if (a < 0)
	{
		printf("负");
		a = -a;
	}
	int mask = 1;
	int t = a;
	int i = 1;
	while (t > 9) 
	{
		t /= 10;
		mask *= 10;
		i++;
	}
	do
	{
		int d = a / mask;
		switch (d)
		{
		case 0:printf("零");break;
		case 1:printf("一"); break;
		case 2:printf("二"); break;
		case 3:printf("三");break;
		case 4:printf("四");break;
		case 5:printf("五");break;
		case 6:printf("六");break;
		case 7:printf("七");break;
		case 8:printf("八");break;
		case 9:printf("九");break;
		}
		if (d != 0) 
		{
			switch (i)
			{
			case 5:printf("万");break;
			case 4:printf("千");break;
			case 3:printf("百");break;
			case 2:printf("十");break;
			}
		}
		a %= mask;
		mask /= 10;
		i--;
	} while (mask > 0);
	printf("\n");
}

int main() 
{
	int a;
	scanf("%d", &a);
	read(a);

	return 0;
}