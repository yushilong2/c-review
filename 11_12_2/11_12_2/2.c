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
			printf("该数字在第%d行第%d列\n", x + 1, y + 1);
			return 1;
		}
	}
	return 0;
}

int main()
{
	//杨氏矩阵
	//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的
	//请编写程序在这样的矩阵中查找某个数字是否存在
	//要求：时间复杂度小于O(N);

	//1 2 3
	//4 5 6
	//7 8 9
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	//看第一列，如果比输入数字大，该行不会有该数
	//看最后一列，如果比输入数字小，这一行不会有该数
	int k = 7;
	int ret = FindNum(arr, k, 3, 3);
	if (ret == 1)
	{
		printf("找到了\n");
	}
	else
	{
		printf("找不到\n");
	}

	return 0;
}