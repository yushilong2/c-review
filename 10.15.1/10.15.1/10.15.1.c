#include<stdio.h>
int main()
{
	//1.不适用取模运算符（%），求整数a除以b的余数？
	int a = 59, b = 6, c = 0;
	c = a - (a / b) * b;
	printf("c=%d\n", c);

	//2.使用位运算判断int型变量a是奇数还是偶数
	//奇数的二进制位低位是1，偶数低位一定是0
	//	xxx1
	//&	0001
	//-------
	//	0001
	if (a & 1)
	{
		printf("是一个奇数\n");
	}
	else printf("是一个偶数\n");

	return 0;
}