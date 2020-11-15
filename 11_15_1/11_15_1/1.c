#include<stdio.h>
#include<string.h>
int main()
{
	//realloc
	//调整动态开辟内存空间的大小
	int* p = (int*)malloc(20);
	if (p == NULL) 
	{
		printf("%s\n", strerror(errno));
	}
	else 
	{
		int i = 0;
		for (i = 0;i < 5;i++)
		{
			*(p + i) = i;
		}
	}
	//只是在使用malloc开辟的20个字节空间
	//假设，20个字节不能满足使用
	//希望能够有40个字节空间
	//这里就可以使用realloc来调整动态开辟的内存
	
	//realloc使用注意事项：
	//1.如果p指向的空间之后有足够的内存空间可以追加，则直接追加，后返回p
	//2.如果p指向的空间之后没有足够的内存空间可以追加，则relloc函数会重新找一个新的内存区域，
	//开辟一块满足需求的空间，并且把原来内存中的数据拷贝回来，释放旧的内存空间，最后返回心开辟的内存空间地址
	//3.得用一个新的变量来接收realloc函数的返回值
	int* ptr = realloc(p, 40);
	if (ptr != NULL)
	{
		p = ptr;
		int i = 0;
		for (i = 5;i < 10;i++)
		{
			*(p + i) = i;
		}
		for (i = 0;i < 10;i++)
		{
			printf("%d", *(p + i));
		}
	}

	return 0;
}