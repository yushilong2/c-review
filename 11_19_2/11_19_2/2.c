#include<stdio.h>
int main()
{
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");//wb：写，二进制
	//文件不存在时，fopen会创建
	fwrite(&a, 4, 1, pf);//在a写4个字节的1个数据，放在pf
	fclose(pf);
	pf = NULL;

	return 0;
}