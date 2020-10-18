#include<stdio.h>
#define MYINT int
int main() 
{
	int a = 10, b = 20, c = 30;
	printf("a=%d,b=%d,c=%d\n", a, b, c);
	//指针到底是什么：内存地址
	//存储在内存里面，存储在内存中的哪个位置：&：取地址运算符
	//%p：打印一个地址（十六进制）
	printf("a的地址：%#p,b的地址：%#p，c的地址：%#p\n",&a, &b, &c);
	//常量：在程序运行过程当中值不可以发生改变的量
	//指针：指针常量，指针变量
	//指针变量：存储的是地址
	char* p;//p的类型就是char*，指向char型的指针
	short* p1;
	int *p2;
	//*靠近类型和靠近变量名，是没有区别的
	//int* p1,p2,p3,p4,p5;里只有p1是int型指针，其它全是int型

	//typedef和define的区别：
	return 0;
}