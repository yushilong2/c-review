//��ӡ�žſھ���
//Ҫ������������1λ������N,�����1*1��N*N�Ĳ��ֿھ���
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i=1;
	while (i < n + 1)
	{
		int j = 1;
		while (j < i + 1)
		{
			printf("%d*%d=%d", j, i, j * i);
			if (i * j < 10) 
			{
				printf("  ");
			}
			else 
			{
				printf(" ");
			}
			j++;
		}
		i++;
		printf("\n");
	}

	return 0;
}