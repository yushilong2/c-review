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

	return 0;
}