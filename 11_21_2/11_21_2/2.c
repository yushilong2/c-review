#include<stdio.h>
#include<errno.h>
int main()
{
	//�Ӽ�������
	//�������Ļ
	//���̺���Ļ�����ⲿ�豸
	//����-��׼�����豸
	//��Ļ-��׼����豸
	//��һ������Ĭ�ϴ򿪵��������豸
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
	//���ļ�
	fgets(buf, 1024, pf);
	printf("%s", buf);//��ѻ��з�Ҳ�Ž�ȥ
	//puts���Դ�����
	fgets(buf, 1024, pf);
	printf("%s", buf);
	//�ر�
	fclose(pf);
	pf = NULL;

	FILE* pf2 = fopen("test2.txt", "w");
	if (pf2 == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	//д�ļ�
	fputs("hello\n", pf2);
	fputs("world", pf2);
	//�ر�
	fclose(pf2);
	pf2 = NULL;

	return 0;
}