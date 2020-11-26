#include<stdio.h>

#define MAX 100
#define STR "hehe"
#define reg register
#define do_forever for(;;)
#define SQUARE(X) X*X
#define DOUBLE(X) X+X
#define DOU(X) ((X)+(X))
//尽量不要在后面加；，会导致检查错误时发现不了

int main()
{
	reg int a;//register int a;
	printf("%d\n", MAX);
	printf("%s\n", STR);
	//do_forever;//死循环
	int ret = SQUARE(5 + 1);
	printf("%d\n", ret);//是替换不是传参，所以是5+1*5+1=5+5+1=11
	int b = 5;
	int r = 10 * DOUBLE(b);
	printf("%d\n", r);//10*5+5=55
	r = 10 * DOU(b);
	printf("%d\n", r);//10*((5)+(5))=100

	return 0;
}

//C语言
//C语言实现数据结构（简单数据结构）：顺序表、链表、栈、队列、二叉树及相关面试题
//C++
//C++实现高级数据结构

//Linux系统
//MySQL