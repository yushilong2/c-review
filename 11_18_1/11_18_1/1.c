#include<stdio.h>
#include<stdlib.h>
//struct S
//{
//	int n;
//	char c;
//	int arr[0];//���������Ա
//};

struct S
{
	int n;
	int arr[];//���������Ա
};

int main()
{
	int i = 0;
	struct S* p = malloc(sizeof(struct S) + 10 * sizeof(int));
	p->n = 100;
	p->arr[i];
	for (i = 0;i < 10;i++)
	{
		p->arr[i] = i;
	}
	for (i = 0;i < 10;i++)
	{
		printf("%d ", p->arr[i]);
	}
	free(p);
	p = NULL;

	return 0;
}