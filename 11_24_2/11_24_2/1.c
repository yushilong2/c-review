#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define PRINT(X) printf("the value of "#X" is %d\n",X)
#define CAT(X,Y) X##Y
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define TEST(x,y) printf("test\n")
#define SIZEOF(type) sizeof(type)
#define MALLOC(num,type) malloc(num*sizeof(type))
#define NUM 100
#define DEBUG

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

	TEST();
	//ÿ��ʹ�ú��ʱ��һ�ݺ궨��Ĵ�����뵽�����У����Ǻ�Ƚ϶̣�������ܴ�������ӳ���ĳ���
	//����û�취���Ե�

	int ret = SIZEOF(int);
	printf("%d\n", ret);

	int* p = MALLOC(10, int);
	//int* p = (int*)malloc(10 * sizeof(int));

	printf("%d\n", NUM);
#undef NUM
	//printf("%d\n", NUM);//���Ƴ�

	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	for (i = 0;i < 10;i++) 
	{
		arr[i] = 0;
#ifdef DEBUG
	printf("%d ", arr[i]);
#endif
	}

#if defined(DEBUG)
	printf("\nhehe\n");
#endif

#if 1==1
	printf("haha\n");
#elif 2 == 1
	printf("hehe\n");
#else
	printf("hihi\n");
#endif

	return 0;
}