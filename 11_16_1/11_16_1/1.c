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
	//1.对NULL指针解引用操作
	/*int* p = alloc(40);
	*p = 10;*/
	//malloc开辟空间失败-这里有可能对NULL指针解引用

	//2.对动态开辟内存的越界访问
	//int* p = (int*)malloc(40);//10个int
	//if (p != NULL)
	//{
	//	return 0;
	//}
	//int i = 0;
	////越界
	//for (i = 0;i <= 10;i++)
	//{
	//	*(p + i) = i;
	//}
	//free(p);
	//p = NULL;

	//3.对非动态开辟内存使用free释放
	//int a = 10;
	//int* p = &a;
	////……
	//free(p);
	//p = NULL;

	//4.使用free释放动态开辟内存的一部分
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
	//回收空间
	//free(p);
	//p = NULL;
	//5.对同一块动态内存的多次释放
	//int* p = (int*)malloc(40);
	//if (p = NULL)
	//{
	//	return 0;
	//}
	////使用
	////释放
	//free(p);
	////……
	//free(p);

	//6.动态开辟内存忘记释放（内存泄漏）
	/*while (1)
	{
		malloc(1);
	}*/

	return 0;
}