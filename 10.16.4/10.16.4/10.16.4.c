#include<stdio.h>
//1.输入整数n,逆序输出,45678,87654
void Nixu()
{
	printf("请输入一个整数：\n");
	int num,y;
	scanf("%d", &num);

	while (num != 0)//for循环，已知循环的次数；while，达到某种条件 
	{
		y = num % 10;
		printf("%d", y);
		num = num / 10;
	}
	printf("\n");
}

//2.判断一个输入的三位数是否为水仙花数
//返回 1：是；返回 0：不是；
int Isflower(int num)
{
	int a = num / 100;
	int b = (num / 10) % 10;
	int c = num % 10;

	if (a * a * a + b * b * b + c * c * c == num)
		return 1;
	else
		return 0;
}
//3.求所有水仙花数
int Shuixian()
{
	for (int i = 100;i <= 999;i++)
	{
		int a = i / 100;
		int b = (i / 10) % 10;
		int c = i % 10;
		if (a * a * a + b * b * b + c * c * c == i)
			printf("%d\n",i);
	}
}

int main() 
{
	//Nixu();
	int num;
	Shuixian();
	printf("请输入一个整数：\n");
	scanf("%d", &num);
	if (1 == Isflower(num))
		printf("是水仙花数.");
	else
		printf("不是水仙花数.");

	return 0;
}