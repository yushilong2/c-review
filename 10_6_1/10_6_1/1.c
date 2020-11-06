#include<stdio.h>

struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}* p;

//假设p的值为0x100000.如下表达式的值分别为多少？
//已知，结构体Test类型的变量大小是20个字节。
int main()
{
	int a[5] = { 1,2,3,4,5 };
	int* ptr = (int*)(&a + 1);//a数组后面的指针
	printf("%d,%d\n", *(a + 1), *(ptr - 1));//2,5

	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);//跳过一个结构体，+20：0x00100014
	printf("%p\n", (unsigned long)p + 0x1);//p转换成十进制，1048576+1=10485767：0x00100001
	printf("%p\n", (unsigned int*)p + 0x1);//跳过一个无符号整形：0x00100004

	return 0;
}