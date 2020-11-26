#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include <time.h>
#define MAX 100	//蛇最大节数
/*
* 1.学过C语言
* 2.C语言数组
* 3.熟悉结构体
* 4.程序 按键交互 鼠标交互
* 5.创建图形窗口
* 6.基本绘图
*/
//1.把程序所要用的数据抽象出来
typedef struct pointXY
{
	int x;
	int y;
}MYPOINT;
HWND hwnd = NULL;
//蛇
struct mySnake
{
	int num;
	MYPOINT xy[MAX];
	char postion;//表示方向，标记
}snake;
//食物
struct myFood
{
	MYPOINT foodxy;
	int flag = 0;
	int eatGrade = 0;
}food;
//把方向枚举出来
enum movPostion 
{
	right=1,
	left=2,
	up=3,
	down=4
};
//整个项目划分
//1.初始化蛇
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

//2.绘制蛇
void drawSnake() 
{
	for (int i = 0;i < snake.num;i++) 
	{
		setlinecolor(RED);
		setfillcolor(GREEN);
		fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 10, snake.xy[i].y + 10);
	}
}

//3.移动蛇
void moveSnake()
{
	//除了第一节之外，后面的坐标都是前一节坐标
	for (int i = snake.num - 1;i > 0;i--) 
	{
		snake.xy[i].x = snake.xy[i - 1].x;
		snake.xy[i].y = snake.xy[i - 1].y;
	}
	//蛇头的移动要根据方向标志
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

//4.按键交互
void keyDown() 
{
	char userKey = '\0';//VC getch不需要加下划线
	userKey = _getch();//不可见输入
	switch (userKey) 
	{
	case'w':
	case'W':
	case 72://上
		if (snake.postion != down)//排除蛇朝下时候的情况
		{
			snake.postion = up;
		}
		break;
	case's':
	case'S':
	case 80://下
		if (snake.postion != up)//排除蛇朝上时候的情况
		{
			snake.postion = down;
		}
		break;
	case'a':
	case'A':
	case 75://左
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
//初始化食物
void initFood()
{
	food.foodxy.x = rand() % 64 * 10;//只能是10的整数倍，蛇头才能对齐食物
	food.foodxy.y = rand() % 48 * 10;
	food.flag = 1;
	//食物不能出现在蛇身上
	for (int i = 0;i < snake.num;i++)
	{
		if (food.foodxy.x == snake.xy[i].x && food.foodxy.y == snake.xy[i].y) 
		{
			food.foodxy.x = rand() % 64 * 10;
			food.foodxy.y = rand() % 48 * 10;
		}
	}
}

//绘制食物
void drawFood() 
{
	setlinecolor(GREEN);
	setfillcolor(RED);
	fillrectangle(food.foodxy.x, food.foodxy.y, food.foodxy.x + 10, food.foodxy.y + 10);
}

//蛇吃食物
void eatFood() 
{
	if (food.foodxy.x == snake.xy[0].x && food.foodxy.y == snake.xy[0].y)
	{
		snake.num++;
		food.eatGrade += 10;
		food.flag = 0;
	}

}
//撞墙判定
int snakeDie()
{
	//显示分数
	char grade[100] = { 0 };
	sprintf(grade, "%d", food.eatGrade);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	outtextxy(560, 20, "分数:");
	outtextxy(600, 20, grade);
	//判断蛇是否死亡
	//撞墙
	if (snake.xy[0].x < 0 || snake.xy[0].x>640 || snake.xy[0].y < 0 || snake.xy[0].y >480)
	{
		MessageBox(hwnd, "游戏结束！", "撞墙死亡！", 0);
		return 1;
	}
	//撞自己
	for (int i = 1;i < snake.num;i++)
	{
		if (snake.xy[0].x == snake.xy[i].x && snake.xy[0].y == snake.xy[i].y)
		{
			MessageBox(hwnd, "游戏结束！", "自杀死亡！", 0);
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
		cleardevice();//刷掉路径
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
		Sleep(100);//控制速度
		while (_kbhit()) //kbhit()存在按键操作，返回非零
		{
			keyDown();
		}
	}
	printf("GameOver!");
	closegraph();
	return 0;
}