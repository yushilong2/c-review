//猜数字游戏是令系统随机产生一个100以内的正整数，用户输入一个数对其进行猜测，需要你编写的程序自动对其与随机产生的被才数进行比较
//输入格式：输入第一行中给出2个不超过100的正整数，分别是系统产生的随机数，以及猜测的最大次数N。随后每行给出一个用户的输入，知道出现负数为止
//在一行中输出每次猜测相应的结果，直到输出猜对的结果或“Game Over”则结束
#include<stdio.h>
int main() 
{
	int number, n;
	int inp;
	int finished = 0;
	int cnt = 0;
	scanf("%d %d", &number, &n);
	do 
	{
		scanf("%d", &inp);
		cnt++;
		if (inp < 0)//出现负数，显示GAMEOVER，结束
		{
			printf("Game Over\n");
			finished = 1;
		}
		else if (inp > number)//猜的数大于随机数
		{
			printf("Too Big\n");
		}
		else if (inp < number)//猜的数小于随机数
		{
			printf("Too Small\n");
		}
		else //等于的时候
		{
			if (cnt == 1) //一次
			{
				printf("Bingo!\n");
			}
			else if (cnt <= 3)//三次以内
			{
				printf("Lucky You!\n");
			}
			else //三次以上
			{
				printf("Good Guess!\n");
			}
			finished = 1;//完成
		}
		if (cnt == n) //次数到达规定要求时
		{
			if (!finished) //没有完成输出GAMEOVER
			{
				printf("Game Over\n");
				finished = 1;
			}
		}
	} while (!finished);//完成时终止循环
	return 0;
}