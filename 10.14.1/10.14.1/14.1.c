#include<stdio.h>
int g_age;//全局变量
void show()
{
	static int i = 10;//静态变量：生命周期从程序启动到程序结束
	printf("i=%d\n", i);
	i = i + 1;
}
int main() 
{
	static int i = 23;

	show();
	show();
	show();

	
	printf("i=%d\n",i);

	//寄存器变量：操作速度更快。不一定会分配到寄存器存储，效率差不多
	register int r = 45;

	extern height;//外部变量
	printf("height=%d\n", height);
	//局部变量不会初始化为0，使用之前必须初始化或赋值
	printf("age=%d", g_age);//全局变量，age=0,自动初始化

	return 0;
}