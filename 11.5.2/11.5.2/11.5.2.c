#include<stdio.h>
#include<string.h>
int main()
{
	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//计算的是数组总大小：3*4*4=48
	printf("%d\n", sizeof(a[0][0]));//一个整形的大小：4
	printf("%d\n", sizeof(a[0]));//一行整形的大小：4*4=16
	printf("%d\n", sizeof(a[0] + 1));//a[0]+1是第一行第二个元素的地址：4/8
	printf("%d\n", sizeof(*(a[0] + 1)));//*（a[0]+1）是第一行第二个元素：4
	printf("%d\n", sizeof(a + 1));//a+1是第二行第一个元素的地址：4/8
	//二维数组想成一维数组的时候，一行为一个元素
	printf("%d\n", sizeof(*(a + 1)));//*（a+1）==a[1],第二行大小：4*4=16
	printf("%d\n", sizeof(&a[0] + 1));//第二行地址：4/8
	printf("%d\n", sizeof(*(&a[0] + 1)));//第二行大小：4*4=16
	printf("%d\n", sizeof(*a));//第一行大小：4*4=16
	printf("%d\n", sizeof(a[3]));//sizeof不会真实计算括号里面的，所以数组不在也会运行：4*4=16

	return 0;
}