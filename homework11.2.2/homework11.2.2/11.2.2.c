//������
//����һ�����������ÿ�����ֶ�Ӧ�ĺ��֡�������Ϊ����ʱ��������������֡�
#include<stdio.h>
int read(int a) 
{
	if (a < 0)
	{
		printf("��");
		a = -a;
	}
	int mask = 1;
	int t = a;
	int i = 1;
	while (t > 9) 
	{
		t /= 10;
		mask *= 10;
		i++;
	}
	do
	{
		int d = a / mask;
		switch (d)
		{
		case 0:printf("��");break;
		case 1:printf("һ"); break;
		case 2:printf("��"); break;
		case 3:printf("��");break;
		case 4:printf("��");break;
		case 5:printf("��");break;
		case 6:printf("��");break;
		case 7:printf("��");break;
		case 8:printf("��");break;
		case 9:printf("��");break;
		}
		if (d != 0) 
		{
			switch (i)
			{
			case 5:printf("��");break;
			case 4:printf("ǧ");break;
			case 3:printf("��");break;
			case 2:printf("ʮ");break;
			}
		}
		a %= mask;
		mask /= 10;
		i--;
	} while (mask > 0);
	printf("\n");
}

int main() 
{
	int a;
	scanf("%d", &a);
	read(a);

	return 0;
}