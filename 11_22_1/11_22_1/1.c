#include<stdio.h>
int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	//1.��λ�ļ�ָ��
	fseek(pf, -2, SEEK_END);
	//SEEK_CUR�ļ�ָ��ĵ�ǰλ��
	//SEEK_END�ļ���ĩβλ��
	//SEEK_SET�ļ�����ʼλ��
	//2.��ȡ�ļ�
	int ch = fgetc(pf);
	printf("%c", ch);
	fclose(pf);
	pf = NULL;

	return 0;
}