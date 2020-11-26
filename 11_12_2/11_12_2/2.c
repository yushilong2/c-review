#include<stdio.h>

int FindNum(int arr[3][3], int k, int row, int col)
{
	int x = col - 1;
	int y = 0;
	while (x >= 0 && y <= row - 1)
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
			printf("�������ڵ�%d�е�%d��\n", x + 1, y + 1);
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
	int ret = FindNum(arr, k, 3, 3);
	if (ret == 1)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("�Ҳ���\n");
	}

	return 0;
}