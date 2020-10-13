#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//include 预处理指令 
//.h结尾的文件叫做头文件
//main函数有且仅有一个，C语言代码都是从main函数开始执行，然后从main结束
//int表示反馈一个整除结构
int a=40;//长
int b=20;//宽
int main()
{
	
	printf("你好，余世龙.\n");//在控制台打印一句话
	//  \n：表示换行符，转义字符

	int c = func(a, b);
	int s = funs(a, b);

	printf("长方形周长和面积为：\n");//%d表示格式化输入输出十进制整数
	printf(" c = %d", c);
	printf(" s = %d", s);
	return 0;//程序结束 0：表示正常退出. 1：表示异常退出.
}