#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define PRINT(X) printf("the value of "#X" is %d\n",X)
#define CAT(X,Y) X##Y
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int main()
{
	int a = 10;
	int b = 20;
	printf("the valude of a is %d\n", a);
	PRINT(a);//#X�滻��"a"
	PRINT(b);

	int Class84 = 2019;
	printf("%d\n", Class84);
	printf("%d\n", CAT(Class, 84));
	//Class##84,##������˺ϳ�һ������

	//���и����õĲ���
	int c = a + 1;//c=11,a=10
	printf("a=%d,c=%d\n", a, c);
	c = ++a;//c=11,a=11
	printf("a=%d,c=%d\n", a, c);
	
	a = 10;
	b = 11;
	int max = MAX(a, b);
	printf("%d\n", max);
	//���и�����ʱ
	max = MAX(a++, b++);
	printf("a=%d,b=%d,max=%d\n", a, b, max);//a=11,b=13,max=12
	//������úܸ��ӣ����Ѷ�

	return 0;
}