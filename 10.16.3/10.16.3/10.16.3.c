#include<stdio.h>
#include<math.h>//所有数字函数都在这个头文件
#include<stdlib.h>//srand rand
#include<time.h>//time
#include"3.h"//包含自定义头文件
//<>：表示直接到系统目录下面查找这个头文件，不会到项目目录下面查找
//双引号：首先到项目目录下面查找这个文件，没有系统目录下面查找

//C语言当中：函数是构成参与援最基本的单元
//函数就是一个加工厂
//函数不能嵌套定义,但是可以在函数里面调用函数
//函数分为函数头和函数体两部分
/*
* 返回值类型 函数名（参数1）
	{
		所要实现的具体功能
		return 返回值
	}
*/


int main() //不能调用main函数,会形成死循环
{
	
	//abs,labs,fabs 求绝对值
	float a = fabs(-45.5);
	printf("a=%f\n", a);

	//sin(),cos(),tan()
	a = sin(45);
	printf("a=%f\n", a);
	a = cos(45);
	printf("a=%f\n", a);
	a = tan(45);
	printf("a=%f\n", a);

	//向上取整
	int d = floor(3.9);
	printf("floor=%d\n", d);
	//向下取整
	d = ceil(3.9);
	printf("ceil=%d\n", d);

	//时间函数
	time_t* t = time(NULL);

	//随机函数
	srand((unsigned)time(NULL));//通过time函数进行播种
	int x=rand();
	printf("x=%d\n", x);
	x = rand() % 101;//0->100；余数小于除数
	printf("x=%d\n", x);
	x = rand() % 900 + 100;//三位随机数100->999 = 0->899
	printf("x=%d\n", x);

	//系统函数
	system("dir");

	//调用函数
	int c=add();
	printf("c=%d\n", c);
	//函数的实参
	c = add1(78, 93);
	printf("c=%d\n", c);

	show();
	display();
	int n = Jiecheng(10);
	printf("阶乘=%d\n", n);

	int result = Count(1, 100);
	printf("%d\n", result);
	//尽量一个函数最多一屏幕大小，能够直观看到

	return 0;
}


//无参函数 void
//实现两个整数的加法运算
int add(void)
{
	return 45 + 89;

}

//函数定义
//实现任意两个整数的加法运算
int add1(int a, int b)//函数形参
{
	int c = a + b;
	return c;//return返回值类型一致
}

void show()//void表示这个函数没有返回值
{
	printf("你好\n");
	return;//没有返回值返回可以这么返回，也可以省略return
	//return表示结束函数
	printf("结束\n");
}

void display()
{
	//函数体里面没有内容就是空函数
}

//递归：自己调用自己
//用递归来求阶乘
//10！=10*9*8*7*……*1；
int Jiecheng(int n)
{
	if (n == 1)
		return 1;
	return n * Jiecheng(n - 1);
}

//这个函数能够实现start + start+1 + ... + end;
int Count(int start, int end)
{
	int result = 0;
	for (;start <= end;start++)
	{
		result += start;
	}
	return result;
}