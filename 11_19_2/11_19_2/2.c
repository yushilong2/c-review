#include<stdio.h>
int main()
{
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");//wb��д��������
	//�ļ�������ʱ��fopen�ᴴ��
	fwrite(&a, 4, 1, pf);//��aд4���ֽڵ�1�����ݣ�����pf
	fclose(pf);
	pf = NULL;

	return 0;
}