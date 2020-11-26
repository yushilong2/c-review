#include<stdio.h>
#include<errno.h>
int main()
{
	//打开文件
	//相对路径
	//..表示上一级路径
	//.表示当前路径
	FILE* pf1 = fopen("test.txt", "r");
	//绝对路径
	//FILE* pf2 = fopen("D:\\q\\c\\11_19_2\\11_19_2\\test.txt", "r");
	if (pf1 == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//打开成功，读写文件
	//关闭文件
	fclose(pf1);
	pf1 = NULL;

	FILE* pfWrite = fopen("TEST.txt", "w");
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//写文件
	fputc('y', pfWrite);
	fputc('s', pfWrite);
	fputc('l', pfWrite);
	//关闭
	fclose(pfWrite);
	pfWrite = NULL;

	FILE* pfRead = fopen("TEST.txt", "r");
	if (pfRead == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//读文件
	printf("%c", fgetc(pfRead));
	printf("%c", fgetc(pfRead));
	printf("%c", fgetc(pfRead));
	//关闭
	fclose(pfRead);
	pfRead = NULL;

	return 0;
}