/*
* �߱�������
* 1.�������ӻ����
*		1.1��������initgraph(800,600);
*		1.2�رմ���closegraph();
* 2.������ͼ����
*		2.1����line
*		2.2��Բcircle
*		2.3���Բsolidcircle
*		2.4�����ຯ��settextcolor setlinecolor settxtstyle setbkmode
*		2.5��ʾ���֣�outtextxy
* 3.������
*		3.1�洢�����Ϣ��MOUSEMSG.m;
*		3.2��ȡ�������������Ϣm=GetMouseMsg();
*		3.3���ദ��m.uMsg��
*		switch(m.uMsg)
*		{
*			case WM_MOUSEMOVE;
*				break;
*		}
* 4.������ͼ
*		4.1����IMAGE����ȥ�洢ͼƬ IMAGE img;
*		4.2����ͼƬ��loadimage(&img,"·��");
*		   ������ʽ���أ�loadimage(&img,"·��"int width,int height);
*		4.3��ʾͼƬ��putimage(int x,int y,&img);
* 5.����
*		5.1ͷ�ļ�+���ؾ�̬��
*		#include<mmsystem.h>
*		#pragma comment(lib,"winmm.lib")
*		5.2������
*		mciSendString("open 1.mp3 alias music,0,0,0");//�����֣����ļ����������music
*		5.3��������
*		mciSendString("play music repeat",0,0,0");
*/
/*
* ��Ŀ����
* 1.������Դ
* 2.����ť
* 3.��ʾͼƬ
* 4.�û������������ť�¼���
*/
/**********************************************************
* C���Ա�׼ͷ�ļ���stdio.h
* ͼ�ο�ͷ�ļ���graphics.h�����л�ͼ�����������ͷ�ļ�
* ��ѧ������math.h
* �������֣�mmsystem.h
***********************************************************/
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

/***********************************************************
* ��������Ҫһ������
* ���Ŵ���Ƭ�����鳤��Ϊ4
* ����С��Ƭ�����鳤��Ϊ4
************************************************************/
IMAGE bkImg;//��ű���
IMAGE Pbig[4];//������Ŵ���Ƭ
IMAGE Psmall[4];//�������С��Ƭ
int smallNum = -1;//��¼������Ƭ��ҳ��
/***********************************************************
* ��װ������ʼ�����ݣ���ʼ������
* loadResource();
************************************************************/
void loadResource()
{
	mciSendString("open 1.mp3 alias music",0,0,0);
	mciSendString("play music repeat", 0, 0, 0);
	loadimage(&bkImg, "bk.jpg");
	//�������أ��ļ������и�ʽ
	for (int i=0;i<4;i++) 
	{
		char fileName[20] = "";
		sprintf(fileName, "%d.jpg", i);
		loadimage(Pbig+i,fileName,250,350);
		loadimage(Psmall + i, fileName, 100, 130);
	}

}
/***********************************************************
* ��ť����
* ����ť
* drawButton();
************************************************************/
void drawButton(int x, int y, char postion)//x,y���꣬postion����
{
	setfillcolor(BLACK);//���������ɫΪ��ɫ
	solidcircle(x, y, 20);//��һ����x��yΪԲ�İ뾶20��Բ
	setlinecolor(WHITE);//�����ߵ���ɫΪ��ɫ
	setlinestyle(PS_SOLID, 3, 0);//�����ߵĸ�ʽ
	circle(x, y, 15);
	line(x - 10, y, x + 10, y);
	if (postion == 'l')
	{
		line(x - 5, y + 4, x - 10, y);
		line(x - 5, y - 4, x - 10, y);
	}
	else if (postion == 'r')
	{
		line(x + 5, y + 4, x + 10, y);
		line(x + 5, y - 4, x + 10, y);
	}
}
/***********************************************************
* ��װ������ʼ������
* ������
* drawMap();
************************************************************/
void drawMap()
{
	//������
	putimage(0, 0, &bkImg);
	//��Сͼ,��0�ź͵�1��
	putimage(150, 160, Psmall+0);//100,130
	putimage(150, 310, Psmall + 1);
	//����ͼ
	putimage(430, 120, Pbig + 0);
	//����ť
	drawButton(170, 130, 'l');
	drawButton(230, 130, 'r');
	//��ӡ����
	settextcolor(BLUE);//����������ɫ
	settextstyle(25, 0,"JOKERMAN");//�����ִ�С������
	setbkmode(TRANSPARENT);//͸�����ֱ���
	outtextxy(400, 65, "For my future ����д�漯 v1.0�汾");
}
/***********************************************************
* �����û�����
* ��������밴ť�Ľ���
* clickButton();
************************************************************/
void clickButton(int x,int y,char postion) 
{
	setfillcolor(BLACK);//���������ɫΪ��ɫ
	solidcircle(x, y, 20);//��һ����x��yΪԲ�İ뾶20��Բ
	setlinecolor(RED);//�����ߵ���ɫΪ��ɫ
	setlinestyle(PS_SOLID, 3, 0);//�����ߵĸ�ʽ
	circle(x, y, 15);
	line(x - 10, y, x + 10, y);
	if (postion == 'l')
	{
		line(x - 5, y + 4, x - 10, y);
		line(x - 5, y - 4, x - 10, y);
	}
	else if (postion == 'r')
	{
		line(x + 5, y + 4, x + 10, y);
		line(x + 5, y - 4, x + 10, y);
	}
}
/***********************************************************
* ������
* СͼƬ�л�ʱ�ľ���
* drawRect();
************************************************************/
void drawRect(int flag) 
{
	if (flag == 1) 
	{
		setlinecolor(GREEN);
		rectangle(145, 155, 255, 295);//��Ƭ��С100*130
		setlinecolor(WHITE);
		rectangle(145, 305, 255, 445);
	}
	else if (flag == 2) 
	{
		setlinecolor(GREEN);
		rectangle(145, 305, 255, 445);
		setlinecolor(WHITE);
		rectangle(145, 155, 255, 295);
	}
}
/***********************************************************
* �����û�����
* ����������
* userMoveMouse();
************************************************************/
void userMoveMouse() 
{
	MOUSEMSG m;
	int flag = 1;
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE://����ƶ�ʱ
			//����Ƿ��ڰ�ť�ϣ��ж���������ǲ�����Բ����
			if (sqrt((double)(m.x - 170) * (m.x - 170) + (m.y - 130) * (m.y - 130)) < 20)
			{
				clickButton(170, 130, 'l');
			}
			else if (sqrt((double)(m.x - 230) * (m.x - 230) + (m.y - 130) * (m.y - 130)) < 20)
			{
				clickButton(230, 130, 'r');
			}
			else//����ƿ�ʱ��ԭ��ť
			{
				drawButton(170, 130, 'l');
				drawButton(230, 130, 'r');
			}
			break;
		case WM_LBUTTONDOWN://��갴��ʱ
			if (sqrt((double)(m.x - 230) * (m.x - 230) + (m.y - 130) * (m.y - 130)) < 20)
			{
				smallNum++;
				if (smallNum == 4)//ͼƬȫ�����꣬ѭ��һ��
				{
					putimage(150, 160, Psmall + 0);
					putimage(150, 310, Psmall + 1);
					smallNum = 0;
				}
				if (smallNum == 2)
				{
					putimage(150, 160, Psmall + 2);
					putimage(150, 310, Psmall + 3);
				}
				drawRect(flag);
				putimage(430, 120, Pbig + smallNum);
			}
			else if (sqrt((double)(m.x - 170) * (m.x - 170) + (m.y - 130) * (m.y - 130)) < 20)
			{
				smallNum--;
				if (smallNum < 0)//��ͷ����
				{
					flag = 2;
					putimage(150, 160, Psmall + 2);
					putimage(150, 310, Psmall + 3);
					smallNum = 3;
				}
				if (smallNum == 1)
				{
					putimage(150, 160, Psmall + 0);
					putimage(150, 310, Psmall + 1);
				}
				drawRect(flag);
				putimage(430, 120, Pbig + smallNum);
			}
			flag++;
			if (flag == 3)
				flag = 1;
			break;
		}
	}
}

int main() 
{
	initgraph(932, 538);
	loadResource();
	drawMap();
	userMoveMouse();
	getchar();
	closegraph();
	return 0;
}