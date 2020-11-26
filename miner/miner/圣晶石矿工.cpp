/*
* ��Ŀ������ʥ��ʯ��
* ���ߣ�������
* �����vs+easyx
*/
#include<stdio.h>
#include<math.h>
#include<graphics.h>//easyx����ͷ�ļ�������ʹ���ṩ�Ľӿڣ�����
#define WIN_WINDTH 1080
#define WIN_HEIGHT 640
#define MAX_IMAGE 11//���ͼƬ����
#define MAX_MINE 10//�����Ʒ����
#define MAX_ANGLE 80//���Ƕ�
#define PI 3.1415926535898
//int a,char b
enum MINE//ö��ͼƬ�����±�
{
	i_gold = 1,
	i_money = 3,
	i_soledown = 5,
	i_soleuo = 7,
	i_stone = 9,
	i_bk = MAX_IMAGE - 1,
};
enum MINE_TYPE //��Ʒ����ö��
{
	GOLD,
	MONEY,
	STONE,
};
enum HOOK_DIR //���ӷ���
{
	LEFT,
	RIGHT,
	M_LONG,
	M_SHORT,
	M_NOMAL,
};
struct Sole //��ɫ��Ϣ
{
	int x;//��ͼλ��
	int y;
	int width;//ͼƬ���
	int heighr;
	int coin;//���
}sole;
struct Mine//��Ʒ
{
	int x;
	int y;
	int size; //�߽��ж�
	bool flag;//�Ƿ����
	int type;//��Ʒ����
	int gold;//��Ʒ��ֵ
}mine[MAX_MINE];
struct HOOK//����
{
	int x;
	int y;
	int endx;
	int endy;
	int len;//����
	int angle;//�Ƕ�
	int dir;//�ڶ�����
	int vx;
	int vy;
	int state;//����״̬
	int index;//��¼ץ������Ʒ�±�
}hook;
int distance(HOOK hook);
IMAGE img[MAX_IMAGE];
//��ʼ������
void GameInit()
{
	//�������� init ��ʼ�� graphicsͼ�ν���
	initgraph(WIN_WINDTH, WIN_HEIGHT, SHOWCONSOLE);
	//�������������
	srand(GetTickCount());
	//����ͼƬ
	for (int i = 0;i < MAX_IMAGE;i++)
	{
		char temp[25] = "";
		sprintf(temp, "./images/%d.jpg", i);
		if (i <= 1)
		{
			loadimage(&img[i], temp, 73, 62);
		}
		else
		{
			loadimage(&img[i], temp);//ע������ַ�������
		}
	}
	loadimage(&img[i_bk], "./images/bk.jpg", WIN_WINDTH, WIN_HEIGHT - 120);
	//��ʼ����ɫ��Ϣ
	sole.width = 140;
	sole.heighr = 120;
	sole.x = WIN_WINDTH / 2 - sole.width / 2;//x�����
	sole.y = 0;
	sole.coin = 0;
	//��ʼ����Ʒ��Ϣ
	for (int i = 0;i < MAX_MINE;i++)
	{
		mine[i].flag = true;
		mine[i].gold = rand() % 200 + 1;
		mine[i].size = 60;
		mine[i].type = rand() % 3;
		mine[i].x = rand() % (WIN_WINDTH - 60);
		mine[i].y = rand() % (WIN_HEIGHT - 150) + 150;
	}
	//��ʼ������
	hook.x = sole.x + 40;
	hook.y = sole.y + 95;
	hook.len = 50;
	hook.endx = hook.x;
	hook.endy = hook.y + hook.len;
	hook.angle = 0;
	hook.dir = RIGHT;
	hook.vx = 0;
	hook.vy = 0;
	hook.state = M_NOMAL;
	hook.index = -1;
}
//��Ϸ����
void GameDraw()
{
	//���Ʊ���
	putimage(0, 120, &img[i_bk]);
	//���ƽ�ɫ������ɫ
	setfillcolor(RGB(255, 245, 247));
	solidrectangle(0, 0, WIN_WINDTH, 120);
	//���ƽ�ɫ
	putimage(sole.x, sole.y, &img[i_soledown - 1], SRCAND);//
	putimage(sole.x, sole.y, &img[i_soledown], SRCPAINT);
	//���Ʒ���
	char score[30] = "";
	sprintf(score, "������%d", sole.coin);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, "����");
	outtextxy(20, 20, score);
	//���ƹ���
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 5);
	line(hook.x, hook.y, hook.endx, hook.endy);
	//������Ʒ
	for (int i = 0;i < MAX_MINE;i++)
	{
		if (mine[i].flag == true)
		{
			switch (mine[i].type)
			{
			case GOLD:
				putimage(mine[i].x, mine[i].y, &img[i_gold - 1], SRCAND);
				putimage(mine[i].x, mine[i].y, &img[i_gold], SRCPAINT);
				break;
			case MONEY:
				putimage(mine[i].x, mine[i].y, &img[i_money - 1], SRCAND);
				putimage(mine[i].x, mine[i].y, &img[i_money], SRCPAINT);
				break;
			case STONE:
				putimage(mine[i].x, mine[i].y, &img[i_stone - 1], SRCAND);
				putimage(mine[i].x, mine[i].y, &img[i_stone], SRCPAINT);
				break;
			}
		}
	}
}
//���Ӱڶ�
void HookRock()
{
	if (hook.state == M_NOMAL)
	{
		if (hook.dir == RIGHT)
		{
			hook.angle++;
		}
		else
		{
			hook.angle--;
		}
		if (hook.angle > MAX_ANGLE)
		{
			hook.dir = LEFT;
		}
		else if (hook.angle < -MAX_ANGLE)
		{
			hook.dir = RIGHT;
		}
		//�Ƕ�ת���� PI/180*�Ƕ�
		hook.endx = hook.x + sin(PI / 180 * hook.angle) * hook.len;
		hook.endy = hook.y + cos(PI / 180 * hook.angle) * hook.len;
	}
}
//��Ϸ����
void GameControl(int speed)
{
	if (GetAsyncKeyState(VK_SPACE) && hook.state == M_NOMAL)
	{
		hook.vx = sin(PI / 180 * hook.angle) * speed;
		hook.vy = cos(PI / 180 * hook.angle) * speed;
		hook.state = M_LONG;
	}
	//�����߽緵��
	if (hook.endx<0 || hook.endx>WIN_WINDTH || hook.endy > WIN_HEIGHT)
	{
		hook.state = M_SHORT;

	}
	if (hook.state == M_LONG)
	{
		hook.endx += hook.vx;
		hook.endy += hook.vy;
	}
	else if (hook.state == M_SHORT)
	{
		hook.endx -= hook.vx;
		hook.endy -= hook.vy;
		//�������
		if (distance(hook))
		{
			hook.state = M_NOMAL;
		}
	}
}
void JudgeGrap()
{
	//�ж�ץ���ĸ���Ʒ
	for (int i = 0;i < MAX_MINE;i++)
	{
		if (mine[i].flag == true &&
			hook.endx > mine[i].x && hook.endx<mine[i].x + mine[i].size &&
			hook.endy > mine[i].y && hook.endy < mine[i].y + mine[i].size)
		{
			hook.index = i;
			break;
		}
	}
	//���ץ����
	if (hook.index != -1)
	{
		hook.state = M_SHORT;
		mine[hook.index].x = hook.endx;
		mine[hook.index].y = hook.endy;
		if (distance(hook))
		{
			mine[hook.index].flag = false;
			hook.index = -1;
			hook.state = M_NOMAL;
		}
	}
}

int main()
{
	GameInit();
	DWORD t1, t2;
	t1 = t2 = GetTickCount();
	BeginBatchDraw();
	while (1)
	{
		//�ﵽ������Ч��
		if (t2 - t1 > 15)
		{
			HookRock();
			t1 = t2;
		}
		t2 = GetTickCount();
		GameDraw();
		FlushBatchDraw();
		GameControl(10);
		JudgeGrap();
		//��ֹ����
	}
	return 0;
}
int distance(HOOK hook)
{
	int dis = sqrt((float)(hook.x - hook.endx) * (hook.x - hook.endx) + (hook.y - hook.endy) * (hook.y - hook.endy));
	return dis <= hook.len;
}