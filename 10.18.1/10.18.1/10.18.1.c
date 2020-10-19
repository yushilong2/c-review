#include<stdio.h>
#define MYINT int
typedef int MYPLUSINT;

#define PMYINT int*
typedef int* PMYPLUSINT;

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
	//char* p;//p的类型就是char*，指向char型的指针
	//short* p1;
	//int *p2;
	//*靠近类型和靠近变量名，是没有区别的
	//int* p1,p2,p3,p4,p5;里只有p1是int型指针，其它全是int型

	//要全部定义指针变量
	//int* p1, * p2, * p3, * p4, * p5;

	//typedef和define的区别：
	//起别名
	MYINT n;//n的类型：int,进行预处理时替换MYINT为int
	MYPLUSINT m;//m的类型：int MYPLUSINT，定义了新名字

	//PMYINT p1, p2,p3,p4;//这里定义了一个指针变量
	//PMYPLUSINT p1, p2, p3, p4;//这里定义了四个指针变量

	//指针的初始化,指针一定要进行初始化，没有初始化的指针不能使用
	int* pa = &a, * pb = &b, * pc = &c;
	printf("pa=%p,pb=%p,pc=%p\n", pa, pb, pc);

	//空指针(NULL)
	int* pd = NULL;
	printf("pd=%p\n", pd);

	//间接访问

	return 0;
}