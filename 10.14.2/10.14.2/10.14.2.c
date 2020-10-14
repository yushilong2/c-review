#include <stdio.h>
int main()
{
	//1.不适用第三个变量来交换两个变量的值
	int a=40, b=55;
	//第一种方法：
	/*
	a = a + b;
	b = a - b;
	a = a - b;
	printf("交换之后：a=%d，b=%d", a, b);
	*/

	//第二种方法：
	/*
	a = a * b;
	b = a / b;
	a = a / b;
	printf("交换之后：a=%d，b=%d", a, b);
	*/

	//第三种方法：
	a = a ^ b;//异或
	b = a ^ b;
	a = a ^ b;
	printf("交换之后：a=%d，b=%d\n", a, b);

	//2.请输入一个三位数，分别打印百位，十位，个位
	int num = 321;
	printf("百位：%d\n", num / 100);
	printf("十位：%d\n", (num % 100)/10);
	printf("个位：%d\n", num % 10);

	return 0;
}