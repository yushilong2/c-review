#include<stdio.h>
#include<math.h>
int main() 
{
	//1.求一元二次方程
	//a*x*x+b*x+c=0
	//int a, b, c;
	//float x1, x2,deta;
	//printf("请输入三个整数：\n");
	//scanf("%d%d%d", &a, &b, &c);
	//printf("一元二次方程：%d*x*x+%d*x+%d=0的方程解为：", a, b, c);
	////公式法：
	//deta = b * b - 4 * a * c;
	//	if (deta == 0)
	//	{
	//		x1 = x2 = (-b) / (float)(2 * a);
	//		printf("x1=x2=%f\n", x1);
	//	}
	//	if (deta > 0)
	//	{
	//		x1 = ((-b) + sqrt(deta)) / (float)(2 * a);
	//		x2 = ((-b) - sqrt(deta)) / (float)(2 * a);
	//		printf("x1=%f,x2=%f\n", x1, x2);
	//	}
	//	else
	//		printf("此方程无解.\n");

	//2.求1->100的素数
	//素数的概念：只能被1和自身整除的数
	int i, j, b;
	for (i = 2;i < 100;i++) 
	{
		b = 0;//素数
		for (j = 2;j < i;j++)
		{
			if (i % j == 0)//不是素数
			{
				b = 1;//合数
				break;
			}
		}
		if (b == 0)
			printf("%d,", i);
	}
	
	return 0;
}