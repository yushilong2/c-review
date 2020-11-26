#include<stdio.h>
int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	//1.定位文件指针
	//fseek(pf, -2, SEEK_END);
	//SEEK_CUR文件指针的当前位置
	//SEEK_END文件的末尾位置
	//SEEK_SET文件的起始位置
	//2.读取文件
	/*int ch = fgetc(pf);
	int pos = ftell(pf);
	printf("%c\n", ch);
	printf("%d\n", pos);*/
	int ch = fgetc(pf);
	printf("%c\n", ch);
	ch = fgetc(pf);
	printf("%c\n", ch);
	rewind(pf);//让文件指针恢复到起始位置
	ch = fgetc(pf);
	printf("%c\n", ch);

	fclose(pf);
	pf = NULL;

	return 0;
}