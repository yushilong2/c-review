#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	int* p2 = realloc(p, 80);
//	if (p2 != NULL)
//	{
//		p = p2;
//	}
//	int* p3 = realloc(NULL, 40);
//	return 0;
//}

int main()
{
	//1.��NULLָ������ò���
	/*int* p = alloc(40);
	*p = 10;*/
	//malloc���ٿռ�ʧ��-�����п��ܶ�NULLָ�������

	//2.�Զ�̬�����ڴ��Խ�����
	//int* p = (int*)malloc(40);//10��int
	//if (p != NULL)
	//{
	//	return 0;
	//}
	//int i = 0;
	////Խ��
	//for (i = 0;i <= 10;i++)
	//{
	//	*(p + i) = i;
	//}
	//free(p);
	//p = NULL;

	//3.�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
	//int a = 10;
	//int* p = &a;
	////����
	//free(p);
	//p = NULL;

	//4.ʹ��free�ͷŶ�̬�����ڴ��һ����
	//int* p = (int*)malloc(40);
	//if (p = NULL)
	//{
	//	return 0;
	//}
	//int i = 0;
	//for (i = 0;i < 10;i++)
	//{
	//	*p++ = i;
	//}
	//���տռ�
	//free(p);
	//p = NULL;
	//5.��ͬһ�鶯̬�ڴ�Ķ���ͷ�
	//int* p = (int*)malloc(40);
	//if (p = NULL)
	//{
	//	return 0;
	//}
	////ʹ��
	////�ͷ�
	//free(p);
	////����
	//free(p);

	//6.��̬�����ڴ������ͷţ��ڴ�й©��
	/*while (1)
	{
		malloc(1);
	}*/

	return 0;
}