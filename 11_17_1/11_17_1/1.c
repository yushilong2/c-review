#include<stdio.h>
#include<string.h>
struct S
{
	int n;
	int arr[];//δ֪��С�ģ����������Ա������Ĵ�С�ǿ��Ե�����
};

int main() 
{
	//struct S s;
	//printf("%d\n", sizeof(s));//4
	struct S* ps =(struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
	ps->n = 100;
	int i = 0;
	for (i = 0;i < 5;i++)
	{
		ps->arr[i] = i;//0 1 2 3 4
	}
	struct S* ptr = realloc(ps, 44);
	if (ptr != NULL)
	{
		ps = ptr;
	}
	for (i = 5;i < 10;i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0;i < 10;i++)
	{
		printf("%d ", ps->arr[i]);
	}
	//�ͷſռ�
	free(ps);
	ps = NULL;
	return 0;
}