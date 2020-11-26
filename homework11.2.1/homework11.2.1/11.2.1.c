//约分最简分式
//输入格式：输入在一行中给出一个分数，分子和分母中间以斜杠“/”分隔，如：12/34表示34分之12.分子和分母都是正整数（不包含0.如果不清楚整数的定义的话）。
//输出格式：在一行中输出这个分数对应的最简分式，格式与输入的相同，即采用“分子/分母”的形式表示分数。如5/6表示6分之5。
#include<stdio.h>
int main() 
{
	int dividend, divisor;
	scanf("%d/%d", &dividend, &divisor);
	int a = dividend;
	int b = divisor;
	int t;
	//辗转相除法算最大公约数
	while (b > 0) 
	{
		t = a % b;
		a = b;
		b = t;
	}
	printf("%d/%d\n", dividend / a, divisor / a);

	return 0;
}