/*
* 具备能力：
* 1.基本可视化编程
*		1.1创建窗口initgraph(800,600);
*		1.2关闭窗口closegraph();
* 2.基本绘图函数
*		2.1划线line
*		2.2画圆circle
*		2.3填充圆solidcircle
*		2.4设置类函数settextcolor setlinecolor settxtstyle setbkmode
*		2.5显示文字：outtextxy
* 3.鼠标操作
*		3.1存储鼠标信息：MOUSEMSG.m;
*		3.2获取窗口上面鼠标信息m=GetMouseMsg();
*		3.3分类处理（m.uMsg）
*		switch(m.uMsg)
*		{
*			case WM_MOUSEMOVE;
*				break;
*		}
* 4.基本贴图
*		4.1声明IMAGE变量去存储图片 IMAGE img;
*		4.2加载图片：loadimage(&img,"路径");
*		   缩放形式加载：loadimage(&img,"路径"int width,int height);
*		4.3显示图片：putimage(int x,int y,&img);
* 5.音乐
*		5.1头文件+加载静态库
*		#include<mmsystem.h>
*		#pragma comment(lib,"winmm.lib")
*		5.2打开音乐
*		mciSendString("open 1.mp3 alias music,0,0,0");//打开音乐，给文件起别名叫做music
*		5.3播放音乐
*		mciSendString("play music repeat",0,0,0");
*/
/*
* 项目流程
* 1.加载资源
* 2.画按钮
* 3.显示图片
* 4.用户交互（点击按钮事件）
*/
/**********************************************************
* C语言标准头文件：stdio.h
* 图形库头文件：graphics.h，所有绘图函数都在这个头文件
* 数学函数：math.h
* 播放音乐：mmsystem.h
***********************************************************/
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

/***********************************************************
* 背景：需要一个变量
* 四张大照片：数组长度为4
* 四张小照片：数组长度为4
************************************************************/
IMAGE bkImg;//存放背景
IMAGE Pbig[4];//存放四张大照片
IMAGE Psmall[4];//存放四张小照片
int smallNum = -1;//记录翻看照片的页码
/***********************************************************
* 封装函数初始化数据：初始化变量
* loadResource();
************************************************************/
void loadResource()
{
	mciSendString("open 1.mp3 alias music",0,0,0);
	mciSendString("play music repeat", 0, 0, 0);
	loadimage(&bkImg, "bk.jpg");
	//批量加载：文件名字有格式
	for (int i=0;i<4;i++) 
	{
		char fileName[20] = "";
		sprintf(fileName, "%d.jpg", i);
		loadimage(Pbig+i,fileName,250,350);
		loadimage(Psmall + i, fileName, 100, 130);
	}

}
/***********************************************************
* 按钮处理
* 画按钮
* drawButton();
************************************************************/
void drawButton(int x, int y, char postion)//x,y坐标，postion方向
{
	setfillcolor(BLACK);//设置填充颜色为黑色
	solidcircle(x, y, 20);//画一个以x，y为圆心半径20的圆
	setlinecolor(WHITE);//设置线的颜色为白色
	setlinestyle(PS_SOLID, 3, 0);//设置线的格式
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
* 封装函数初始化界面
* 画界面
* drawMap();
************************************************************/
void drawMap()
{
	//画背景
	putimage(0, 0, &bkImg);
	//画小图,第0张和第1张
	putimage(150, 160, Psmall+0);//100,130
	putimage(150, 310, Psmall + 1);
	//画大图
	putimage(430, 120, Pbig + 0);
	//画按钮
	drawButton(170, 130, 'l');
	drawButton(230, 130, 'r');
	//打印文字
	settextcolor(BLUE);//设置文字颜色
	settextstyle(25, 0,"JOKERMAN");//设置字大小和字体
	setbkmode(TRANSPARENT);//透明文字背景
	outtextxy(400, 65, "For my future 黑贞写真集 v1.0版本");
}
/***********************************************************
* 处理用户交互
* 处理鼠标与按钮的交互
* clickButton();
************************************************************/
void clickButton(int x,int y,char postion) 
{
	setfillcolor(BLACK);//设置填充颜色为黑色
	solidcircle(x, y, 20);//画一个以x，y为圆心半径20的圆
	setlinecolor(RED);//设置线的颜色为红色
	setlinestyle(PS_SOLID, 3, 0);//设置线的格式
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
* 画矩形
* 小图片切换时的矩形
* drawRect();
************************************************************/
void drawRect(int flag) 
{
	if (flag == 1) 
	{
		setlinecolor(GREEN);
		rectangle(145, 155, 255, 295);//照片大小100*130
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
* 处理用户交互
* 处理鼠标操作
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
		case WM_MOUSEMOVE://鼠标移动时
			//鼠标是否在按钮上：判断鼠标坐标是不是在圆里面
			if (sqrt((double)(m.x - 170) * (m.x - 170) + (m.y - 130) * (m.y - 130)) < 20)
			{
				clickButton(170, 130, 'l');
			}
			else if (sqrt((double)(m.x - 230) * (m.x - 230) + (m.y - 130) * (m.y - 130)) < 20)
			{
				clickButton(230, 130, 'r');
			}
			else//鼠标移开时还原按钮
			{
				drawButton(170, 130, 'l');
				drawButton(230, 130, 'r');
			}
			break;
		case WM_LBUTTONDOWN://鼠标按下时
			if (sqrt((double)(m.x - 230) * (m.x - 230) + (m.y - 130) * (m.y - 130)) < 20)
			{
				smallNum++;
				if (smallNum == 4)//图片全部放完，循环一次
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
				if (smallNum < 0)//开头按←
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