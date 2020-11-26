#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include <time.h>
#define MAX 100	//��������
/*
* 1.ѧ��C����
* 2.C��������
* 3.��Ϥ�ṹ��
* 4.���� �������� ��꽻��
* 5.����ͼ�δ���
* 6.������ͼ
*/
//1.�ѳ�����Ҫ�õ����ݳ������
typedef struct pointXY
{
	int x;
	int y;
}MYPOINT;
HWND hwnd = NULL;
//��
struct mySnake
{
	int num;
	MYPOINT xy[MAX];
	char postion;//��ʾ���򣬱��
}snake;
//ʳ��
struct myFood
{
	MYPOINT foodxy;
	int flag = 0;
	int eatGrade = 0;
}food;
//�ѷ���ö�ٳ���
enum movPostion 
{
	right=1,
	left=2,
	up=3,
	down=4
};
//������Ŀ����
//1.��ʼ����
void initSnake() 
{
	snake.xy[2].x = 0;
	snake.xy[2].y = 0;

	snake.xy[1].x = 10;
	snake.xy[1].y = 0;

	snake.xy[0].x = 20;
	snake.xy[0].y = 0;

	snake.num = 3;
	snake.postion = right;

	food.flag = 0;
}

//2.������
void drawSnake() 
{
	for (int i = 0;i < snake.num;i++) 
	{
		setlinecolor(RED);
		setfillcolor(GREEN);
		fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 10, snake.xy[i].y + 10);
	}
}

//3.�ƶ���
void moveSnake()
{
	//���˵�һ��֮�⣬��������궼��ǰһ������
	for (int i = snake.num - 1;i > 0;i--) 
	{
		snake.xy[i].x = snake.xy[i - 1].x;
		snake.xy[i].y = snake.xy[i - 1].y;
	}
	//��ͷ���ƶ�Ҫ���ݷ����־
	switch (snake.postion)
	{
	case right:
		snake.xy[0].x += 10;
		break;
	case left:
		snake.xy[0].x -= 10;
		break;
	case up:
		snake.xy[0].y -= 10;
		break;
	case down:
		snake.xy[0].y += 10;
		break;
	}
}

//4.��������
void keyDown() 
{
	char userKey = '\0';//VC getch����Ҫ���»���
	userKey = _getch();//���ɼ�����
	switch (userKey) 
	{
	case'w':
	case'W':
	case 72://��
		if (snake.postion != down)//�ų��߳���ʱ������
		{
			snake.postion = up;
		}
		break;
	case's':
	case'S':
	case 80://��
		if (snake.postion != up)//�ų��߳���ʱ������
		{
			snake.postion = down;
		}
		break;
	case'a':
	case'A':
	case 75://��
		if (snake.postion != right)
		{
			snake.postion = left;
		}
		break;
	case'd':
	case'D':
	case 77:
		if (snake.postion != left)
		{
			snake.postion = right;
		}
		break;
	}
}
//��ʼ��ʳ��
void initFood()
{
	food.foodxy.x = rand() % 64 * 10;//ֻ����10������������ͷ���ܶ���ʳ��
	food.foodxy.y = rand() % 48 * 10;
	food.flag = 1;
	//ʳ�ﲻ�ܳ�����������
	for (int i = 0;i < snake.num;i++)
	{
		if (food.foodxy.x == snake.xy[i].x && food.foodxy.y == snake.xy[i].y) 
		{
			food.foodxy.x = rand() % 64 * 10;
			food.foodxy.y = rand() % 48 * 10;
		}
	}
}

//����ʳ��
void drawFood() 
{
	setlinecolor(GREEN);
	setfillcolor(RED);
	fillrectangle(food.foodxy.x, food.foodxy.y, food.foodxy.x + 10, food.foodxy.y + 10);
}

//�߳�ʳ��
void eatFood() 
{
	if (food.foodxy.x == snake.xy[0].x && food.foodxy.y == snake.xy[0].y)
	{
		snake.num++;
		food.eatGrade += 10;
		food.flag = 0;
	}

}
//ײǽ�ж�
int snakeDie()
{
	//��ʾ����
	char grade[100] = { 0 };
	sprintf(grade, "%d", food.eatGrade);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	outtextxy(560, 20, "����:");
	outtextxy(600, 20, grade);
	//�ж����Ƿ�����
	//ײǽ
	if (snake.xy[0].x < 0 || snake.xy[0].x>640 || snake.xy[0].y < 0 || snake.xy[0].y >480)
	{
		MessageBox(hwnd, "��Ϸ������", "ײǽ������", 0);
		return 1;
	}
	//ײ�Լ�
	for (int i = 1;i < snake.num;i++)
	{
		if (snake.xy[0].x == snake.xy[i].x && snake.xy[0].y == snake.xy[i].y)
		{
			MessageBox(hwnd, "��Ϸ������", "��ɱ������", 0);
			return 1;
		}
	}
	return 0;
}

int main() 
{
	srand((unsigned int)time(NULL));
	hwnd = initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();
	initSnake();
	while (1) 
	{
		cleardevice();//ˢ��·��
		drawSnake();
		if (food.flag == 0)
		{
			initFood();
		}
		drawFood();
		if (snakeDie())
		{
			break;
		}
		moveSnake();
		eatFood();
		if (snakeDie())
		{
			break;
		}
		Sleep(100);//�����ٶ�
		while (_kbhit()) //kbhit()���ڰ������������ط���
		{
			keyDown();
		}
	}
	printf("GameOver!");
	closegraph();
	return 0;
}