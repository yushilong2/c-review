#include<stdio.h>

#define MAX 100
#define STR "hehe"
#define reg register
#define do_forever for(;;)
#define SQUARE(X) X*X
#define DOUBLE(X) X+X
#define DOU(X) ((X)+(X))
//������Ҫ�ں���ӣ����ᵼ�¼�����ʱ���ֲ���

int main()
{
	reg int a;//register int a;
	printf("%d\n", MAX);
	printf("%s\n", STR);
	//do_forever;//��ѭ��
	int ret = SQUARE(5 + 1);
	printf("%d\n", ret);//���滻���Ǵ��Σ�������5+1*5+1=5+5+1=11
	int b = 5;
	int r = 10 * DOUBLE(b);
	printf("%d\n", r);//10*5+5=55
	r = 10 * DOU(b);
	printf("%d\n", r);//10*((5)+(5))=100

	return 0;
}

//C����
//C����ʵ�����ݽṹ�������ݽṹ����˳�������ջ�����С������������������
//C++
//C++ʵ�ָ߼����ݽṹ

//Linuxϵͳ
//MySQL