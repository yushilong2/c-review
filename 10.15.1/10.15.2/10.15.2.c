#include<stdio.h>
int main() 
{
	//if语句：条件判断语，表达式返回真或假.
	//if(表达式)
	/*表达方式：
	*1. if(表达式)
	*		一条语句
	* 
	* 2.if(表达式)
	*		一条语句 
	* else
	*		一条语句
	* 
	* 3.if(表达式)
	*		一条语句
	* else if(表达式)
	*		一条语句
	* ...
	* else if(表达式)
	*		一条语句
	*/
	int a = 10, b = 20;
	int c = a < b;
	printf("c=%d\n", c);
	if (c)
		printf("a<b\n");
	//if后面作用只管一条语句，除非后面是一句语句块
	if (0)
		printf("第一句话\n");
		printf("第二句话\n");

	if (0)
		printf("今天出太阳\n");
	else
		printf("今天在下雨\n");

	//if...else语句只执行一种情况，不会执行多种情况
	if (a > b)
		printf("a>b\n");
	else if (a == b)
		printf("a==b\n");
	else
		printf("a<b\n");

	//if语句的嵌套
	//if语句里面还可以有if语句
	//不要嵌套太深,影响代码阅读
	if (a < 50)
	{
		printf("a<50\n");
		if (a < 30)
		{
			printf("a<30\n");
			if (a == 10)
				printf("a=10\n");
		}
	}

	//switch语句
	/*swich(整形或整形表达式)	可以是字符类型（ASCII码）
	* {
	*		case 常量（不能是变量）、
	*		default;
	* }
	* case里面不能重复匹配
	*/
	int w=6;
	switch (w)
	{
	case 0:
		printf("结束.\n");break;
	case 1:
		printf("今天是星期一.\n");break;//break的作用是跳出switch语句
	case 2:
		printf("今天是星期二.\n");break;
	case 3:
		printf("今天是星期三.\n");break;
	case 4:
		printf("今天是星期四.\n");break;
	case 5:
		printf("今天是星期五.\n");break;
	case  6:case 7:
		printf("星期六和星期日是休息日.\n");break;
	
	default:
		printf("您输入的情况都没有.\n");break;
	}

	//判断你输入的三条边能不能构成三角形
	//任意两边只和大于第三边
	a = 10;b = 20;c = 15;
	if (a + b > c && a + c > b && b + c > a)
		printf("能够构成三角形.\n");
	else
		printf("不能构成三角形.\n");
	//switch语句能，做的if语句都能做
	//if语句能做的，switch语句不一定全能做

	//循环语句
	//while() 直到条件不满足，退出循环
	// 一条语句或一个语句块
	//1+2+3+……+100
	int n = 1,result = 0;
	while (n < 11)
	{
		result = result + n;
		printf("n=%d	result=%d\n", n++,result);
	}
	//循环也可以嵌套
	//九九乘法表
	int i = 1;
	while (i <= 9)
	{
		int j = 1;
		while (j <= i)
		{
			printf("%d*%d=%d ", i, j, i * j);
			j++;
		}
		printf("\n");
		i++;
	}
	//do while循环
	a = 100;
	do
		printf("hello\n");
	while (a<10);
	//不管条件成不成立，先运行一遍
	//for循环
	/*形式：for（语句1；语句2；语句3）
	*	一条语句或语句块
	* 语句1：进行初始化
	* 语句2：判断条件
	* 语句3：条件修正
	*/
	//1+2+3+...+10
	int j = 0;
	for (i = 0, j = 0, n = 0;i < 100, j < 200;i += 5, j += 40)
		n++;
	printf("执行次数：n=%d\n", n);
	//调换位置，次序就会发生改变。逗号表达式，以后为真
	for (i = 0, j = 0, n = 0;j < 200, i < 100;i += 5, j += 40)
			n++;
	printf("执行次数：n=%d\n", n);
	//九九乘法表
	for (i = 1; i < 10;i++)
	{
		for (j = 1;j <= i;j++)
		{
			printf("%d+%d=%d ",i,j,i*j );
		}
		printf("\n");
	}

	return 0;
}
