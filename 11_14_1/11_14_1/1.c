#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

//��̬�ڴ����
int main()
{
	//���ڴ�����10�����εĿռ�
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		//��ӡ����ԭ��
		printf("%s\n", strerror(errno));
	}
	else
	{
		//����ʹ�ÿռ�
		int i = 0;
		for (i = 0;i < 10;i++)
		{
			*(p + i) = i;
		}
		for (i = 0;i < 10;i++)
		{
			printf("%d ", *(p + i));
		}
	}
	//����̬����Ŀռ䲻��ʹ�õ�ʱ��
	//Ӧ����������ϵͳ
	free(p);
	p = NULL;
	return 0;
}