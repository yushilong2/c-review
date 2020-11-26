#include<stdio.h>
#include<string.h>
void GetMemory(char** p)
{
	*p = (char*)malloc(100);
}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	//程序崩溃
//	//程序存在内存泄漏的问题
//	//str以值的形式给p
//	//p是GetMemory函数的形参，只能函数内部有效
//	//等GetMemory函数返回之后，动态开辟内存尚未释放并且无法找到，所以会造成内部泄漏
//	printf(str);
//}
void Test(void)
{
	char* str = NULL;
	GetMemory(&str);
	strcpy(str, "hello world");
	printf(str);
	free(str);
	str = NULL;
}

int main()
{
	Test();
	char* str = "abcdef";
	printf("%s\n", str);
	printf(str);
	printf("abcdef");

	return 0;
}