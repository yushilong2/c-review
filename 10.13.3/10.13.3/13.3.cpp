#include <stdio.h>
int main()
{
	//什么是常量：在程序的运行过程当中，值不可以发生改变的量
	//什么是变量：在程序的运行过程当中，值可以发生改变的量
	//定义一个整形变量,a和b都是变量
	//16位机上int占两个字节，32位机上int占四个字节
	//无符号（0 -> 2^32-1）和有符号(-2^31 -> 2^31-1)
	//不加后缀默认都是int型
	unsigned a=1u;
	signed b=-2;
	printf("a=%d\nb=%d\n", a, b);
	printf("int占用字节：%d\n", sizeof(int));
	//变量的命名：
	//命名规则：
	//1.由字母、数字、下划线组成.
	//2.不能以数字开头.
	//3.严格区分大小写
	//4.不能以C语言关键字作为变量名（32个关键字）

	//命名规范
	//1.见名知义
	//2.变量名不要超过32个字符,超过部分会截断
	
	//1.驼峰命名法：StudentScordMangerSystem
	//2.匈牙利命名法:nStudentScordManferSystem
	//局部变量
	//int : n
	//char : ch
	//float : f
	//double : d
	//指针 : p
	//句柄 : h
	//全局变量 : g_
	char ch = 'a';
	printf("ch=%c\n", ch);
	printf("char占用字节：%d\n", sizeof(char));
	//字符型变量
	//关键字 char
	//在内存中占用一个字节，一个字节占用八个位 1byte=8bit
	//每一个bit只能存0或1
	//char型的存储范围：0->255，最多能够表示256个字符
	//分为有符号（-128->127）和无符号（0->255）
	//10000000(2)=-128(10)
	//unsigned：无符号
	//signed：有符号
	unsigned char ch1 = 255;
	printf("ch1 = %d\n", ch1);
	signed char ch2 = -128;
	printf("ch2 = %d\n", ch2);
	char ch3 = -12;
	printf("ch3 = %d\n", ch3);

	//短整型：short int
	//定义并且初始化
	//占用两个字节
	short s=45;
	printf("s=%d\n",s);
	printf("short占用字节：%d\n", sizeof(short));
	//无符号(0->65535)和有符号(-32768->32767)
	unsigned short s1 = 65535;
	printf("s1 = %d\n", s1);
	signed short s2 = -32768;
	printf("s2 = %d\n", s2);

	//长整形：long int,占用四个字节
	//无符号（0 -> 2^32-1）和有符号(-2^31 -> 2^31-1)
	long int l = 45UL;
	printf("long占用字节：%d\n", sizeof(l));

	//长长整形：long long int，占用8个字节
	long long ll = 78LL;
	printf("long long int占用字节：%d\n", sizeof(long long int));

	//浮点型变量
	//单精度浮点型：float,占用四个字节，精确度小数点后六位
	float f = 78.4f;
	printf("%f\n", f);
	printf("float占用字节：%d\n",sizeof(float));
	//双精度浮点型：double，占用八个字节，精确度小数点后十五位
	double d = 45.6;
	printf("%lf\n", d);
	printf("double占用字节：%d\n", sizeof(double));
	//长双精度浮点型：long double,占用8个字节，gcc上12个字节
	long double ld = 789.7;
	printf("%lf\n", ld);
	printf("long double占用字节：%d\n", sizeof(long double));
	
	//变量的存储类型；
	//自动变量:函数里面定义的局部变量.离开作用域后自动销毁，默认不加auto，表示自动变量


	return 0;
}