#include<stdio.h>
extern int ADD(int x, int y);
int main()
{
	int a = 10;
	int b = 20;
	int c = ADD(a, b);
	printf("c=%d\n", c);


	int arr[10] = { 0 };
	int i = 0;
	for (i = 0;i < 10;i++)
	{
		arr[i] = i;
	}
	for (i = 0;i < 10;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	//预定义符号
	printf("%s\n", __FILE__);
	printf("%d\n", __LINE__);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
	//写日志文件
	int arr2[10] = { 0 };
	FILE* pf = fopen("log.txt", "w");
	for (i = 0;i < 10;i++)
	{
		arr[i] = i;
		fprintf(pf, "file:%s line:%d date:%s time:%s i=%d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);
	}
	fclose(pf);
	pf = NULL;
	printf("%s\n", __FUNCTION__);
	for (i = 0;i < 10;i++)
	{
		printf("%d", arr[i]);
	}

	return 0;
}

//预处理
//文本操作
//#include头文件的包含
//注释删除，使用空格来替换注释
//#define

//把C语言代码翻译成汇编代码
//1.语法分析
//2.词法分析
//3.语义分析
//4.符号汇总

//汇总：
//函数名
//全局变量

//把回避哦按代码转换成二进制指令

//合并段表
//符号表的合并和重定位
