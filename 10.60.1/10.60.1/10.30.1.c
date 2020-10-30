//厘米换算英尺尺寸
//输入格式：输入在一行中给出一个正整数，单位是厘米
//输出格式：在一行中输出这个厘米数对应英制长度的英尺和英寸的整数值，中间用空格分开
#include<stdio.h>
int main() 
{
	int cm = 0;
	scanf("%d", &cm);
	int foot = cm / 30.48;
	int inch = ((cm / 30.48) - foot) * 12;
	printf("%d %d", foot, inch);
	return 0;
}