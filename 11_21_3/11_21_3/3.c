#include<stdio.h>

struct S
{
	int n;
	float score;
	char arr[10];
};

int main()
{
	struct S s = { 100,3.14f,"bit" };
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		return 0;
	}
	//��ʽ������ʽд�ļ�
	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
	//��ʽ������������
	fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);
	printf("%d %f %s\n", s.n, s.score, s.arr);
	//�ر�
	fclose(pf);
	pf = NULL;

	//scanf/printf����Ա�׼������/��׼������ĸ�ʽ������/������
	//fscanf/fprintf���������������/����������ĸ�ʽ������/������
	//sscanf�Ǵ��ַ����ж�ȡ��ʽ�������ݣ�sprintf�ǰѸ�ʽ�������������(�洢��)�ַ���
	struct S s2 = { 100,3.14f,"abcdef" };
	struct S tmp = { 0 };
	char buf[1024] = { 0 };
	//�Ѹ�ʽ��������ת�����ַ����洢��buf
	sprintf(buf, "%d %f %s", s2.n, s2.score, s2.arr);
	//��buf�ж�ȡ��ʽ�������ݵ�tmp��
	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
	printf("%d %f %s\n", tmp.n, tmp.score, tmp.arr);

	return 0;
}