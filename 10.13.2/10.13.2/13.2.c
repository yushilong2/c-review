#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	while (1)
	{
		//请你输入任意一个字母，如果是大写，转换为小写。如果是小写，转换为大写。
		char ch;
		printf("请您输入一个字母：\n");
		scanf("%c", &ch);
		setbuf(stdin, NULL);//清空缓存区,(回车键)
		//判断字母是否为大小写
		//如果为大写
		if (ch >= 'A' && ch <= 'Z')
		{
			printf("它的小写为%c\n", ch + 32);
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			printf("它的大写为%c\n", ch - 32);
		}
		else
		{
			printf("输入错误\n");
		}
	}
	
	return 0;
}