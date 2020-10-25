#include<stdio.h>
#include<string.h>

unsigned int MyStrlen(const char* str)
{
	unsigned int n = 0;
	while (*str != '\0')
	{
		str++;
		n++;
	}
	return n;
}
//查找某个字符
int MyStrchr(const char* str, char ch)
{
	int n = 1;
	while (*str!= '\0') 
	{
		if (*str == ch)
			return n;
		str++;
		n++;
	}
	return -1;
}

int main() 
{
	char* str = "hello";
	char sz[20] = { 'h','e','l','l','o' ,1,2,3 };

	printf("长度=%d\n", strlen(str));
	printf("长度=%d\n", strlen(sz));

	printf("长度=%d\n", MyStrlen(sz));

	//const常量C语言里面可以修改，c++不行
	const int n = 10;
	//int* p = &n;
	//*p = 45;
	printf("n=%d\n", n);
	//有点违背规则

	//更严谨的写法
	//指向整形常量的指针
	const int* p = &n;

	//指针可以是常量
	int m = 20;
	int* const p2 = &m;
	*p2 = 45;
	printf("m=%d\n", m);

	//字符串复制
	//strcpy(sz,str);
	//缓冲区的空间一定要足够，如果不够会导致后面的数据被修改
	//会复制字符串终止符
	//strcpy(sz, str, 8);

	//字符串连接
	strcat(sz, str);//反过来错误，因为str是常量
	
	//字符串比较
	//会逐个比较
	char* str1 = "HelloWorld";
	char* str2 = "H123456789";
	if (strcmp(str1, str2) == 0)
	{
		printf("str1与str2相等\n");
	}
	else 
	{
		printf("str1与str2不相等\n");
	}

	//字符查找
	char* p3 = strchr(str1, 'o');
	printf("%s\n", p3);

	int pos = MyStrchr(str1, 'H');
	printf("pos=%d\n", pos);

	//字符串里面找字符串
	char* p4 = strstr(str1, "lo");
	printf("%s\n", p4);

	return 0;
}