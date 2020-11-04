#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++) 
	{
		for (j = 0;j < col;j++) 
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}

}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家走：>\n");
		printf("请输入要下的坐标：>");
		scanf("%d%d", &x, &y);
		//判断x，y坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else 
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
		
}
void ComputerMove(char board[ROW][COL], int row, int col) 
{
	int x = 0;
	int y = 0;
	printf("电脑走：>\n");
	x = rand() % row;
	y = rand() % col;
	while (1)
	{
		if (board[x][y] == ' ')
		{
			board[x][y] = 'o';
			break;
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++) 
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] || board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
}