#include<stdio.h>
#include<errno.h>
int main()
{
	//���ļ�
	//���·��
	//..��ʾ��һ��·��
	//.��ʾ��ǰ·��
	FILE* pf1 = fopen("test.txt", "r");
	//����·��
	//FILE* pf2 = fopen("D:\\q\\c\\11_19_2\\11_19_2\\test.txt", "r");
	if (pf1 == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//�򿪳ɹ�����д�ļ�
	//�ر��ļ�
	fclose(pf1);
	pf1 = NULL;

	FILE* pfWrite = fopen("TEST.txt", "w");
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//д�ļ�
	fputc('y', pfWrite);
	fputc('s', pfWrite);
	fputc('l', pfWrite);
	//�ر�
	fclose(pfWrite);
	pfWrite = NULL;

	FILE* pfRead = fopen("TEST.txt", "r");
	if (pfRead == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//���ļ�
	printf("%c", fgetc(pfRead));
	printf("%c", fgetc(pfRead));
	printf("%c", fgetc(pfRead));
	//�ر�
	fclose(pfRead);
	pfRead = NULL;

	return 0;
}