//��������Ϸ����ϵͳ�������һ��100���ڵ����������û�����һ����������в²⣬��Ҫ���д�ĳ����Զ���������������ı��������бȽ�
//�����ʽ�������һ���и���2��������100�����������ֱ���ϵͳ��������������Լ��²��������N�����ÿ�и���һ���û������룬֪�����ָ���Ϊֹ
//��һ�������ÿ�β²���Ӧ�Ľ����ֱ������¶ԵĽ����Game Over�������
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
		if (inp < 0)//���ָ�������ʾGAMEOVER������
		{
			printf("Game Over\n");
			finished = 1;
		}
		else if (inp > number)//�µ������������
		{
			printf("Too Big\n");
		}
		else if (inp < number)//�µ���С�������
		{
			printf("Too Small\n");
		}
		else //���ڵ�ʱ��
		{
			if (cnt == 1) //һ��
			{
				printf("Bingo!\n");
			}
			else if (cnt <= 3)//��������
			{
				printf("Lucky You!\n");
			}
			else //��������
			{
				printf("Good Guess!\n");
			}
			finished = 1;//���
		}
		if (cnt == n) //��������涨Ҫ��ʱ
		{
			if (!finished) //û��������GAMEOVER
			{
				printf("Game Over\n");
				finished = 1;
			}
		}
	} while (!finished);//���ʱ��ֹѭ��
	return 0;
}