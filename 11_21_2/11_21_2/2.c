#include<stdio.h>
#include<errno.h>
int main()
{
	//从键盘输入
	//输出到屏幕
	//键盘和屏幕都是外部设备
	//键盘-标准输入设备
	//屏幕-标准输出设备
	//是一个程序默认打开的两个流设备
	//stdin FILE*
	//stdout FILE*
	//stderr FILE*

	//int ch = fgetc(stdin);
	//fputc(ch, stdout);

	char buf[1024] = { 0 };
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	//读文件
	fgets(buf, 1024, pf);
	printf("%s", buf);//会把换行符也放进去
	//puts会自带换行
	fgets(buf, 1024, pf);
	printf("%s", buf);
	//关闭
	fclose(pf);
	pf = NULL;

	FILE* pf2 = fopen("test2.txt", "w");
	if (pf2 == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	//写文件
	fputs("hello\n", pf2);
	fputs("world", pf2);
	//关闭
	fclose(pf2);
	pf2 = NULL;

	return 0;
}