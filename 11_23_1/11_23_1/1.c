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

	//Ԥ�������
	printf("%s\n", __FILE__);
	printf("%d\n", __LINE__);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
	//д��־�ļ�
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

//Ԥ����
//�ı�����
//#includeͷ�ļ��İ���
//ע��ɾ����ʹ�ÿո����滻ע��
//#define

//��C���Դ��뷭��ɻ�����
//1.�﷨����
//2.�ʷ�����
//3.�������
//4.���Ż���

//���ܣ�
//������
//ȫ�ֱ���

//�ѻر�Ŷ������ת���ɶ�����ָ��

//�ϲ��α�
//���ű�ĺϲ����ض�λ
