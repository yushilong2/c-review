#include<stdio.h>

int FindNum(int arr[3][3], int k, int* px, int* py)
{
	int x = *px - 1;
	int y = 0;
	while (x >= 0 && y <= *py - 1)
	{
		if (arr[x][y] > k)
		{
			y++;
		}
		else if (arr[x][y] < k)
		{
			x--;
		}
		else
		{
			*px = x+1;
			*py = y+1;
			return 1;
		}
	}
	return 0;
}

int main()
{
	//���Ͼ���
	//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ�����
	//���д�����������ľ����в���ĳ�������Ƿ����
	//Ҫ��ʱ�临�Ӷ�С��O(N);

	//1 2 3
	//4 5 6
	//7 8 9
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	//����һ�У�������������ִ󣬸��в����и���
	//�����һ�У��������������С����һ�в����и���
	int k = 7;
	int x = 3;
	int y = 3;
	int ret = FindNum(arr, k, &x, &y);
	if (ret == 1)
	{
		printf("�ҵ���\n");
		printf("�ڵ�%d�е�%d��\n", x, y);
	}
	else
	{
		printf("�Ҳ���\n");
	}

	return 0;
}