//求a的连续和
//输入两个整数a和n，a的范围是[0,9]，n的范围是[1,8]，求数列之和S=a+aa+aaa+……+aaa...a(n个a)。
//输入格式：输入在一行中给出两个整数，先后表示a和n。
//输出格式：在一行中输出要求的数列之和
#include<stdio.h>
int main() 
{
	int a, n;
	scanf("%d %d", &a, &n);
	int sum = 0;
	int i;
	int t = 0;
	for (i = 0;i < n;i++)
	{
		t = t * 10 + a;
		sum += t;
	}
	printf("%d\n", sum);

	return 0;
}