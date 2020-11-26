#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
/*
* 创建图形化窗口
* 1.鼠标能够反馈给计算机（窗口）的是什么？
* 坐标，左键，右键--->值
* 重点不是这个值，而是如何存储这个值，如何获取这个值
* C语言定义变量：类型 变量名；
* MOUSEMSG--->类型
* GetMouseMsg--->获取鼠标操作
* 分类讨论这个值，因为鼠标操作有多种
* m.uMsg：讨论鼠标操作的类型
* 分类讨论：
* L:left 左
* R:right 右
* button:按钮
* down:下
* WM_LBUTTONDOWN;
* WM_MOUSEMOVE
*/

int main()
{
	initgraph(800, 600);
	MOUSEMSG m;//存放鼠标值
	while (1)
	{
		m = GetMouseMsg();
		//左键画圆 右键画方
		//画圆：circle(int x,int y,int r);
		//画方：rectangle(int x,int y,int xx,int yy);
		//画线：line(int x,int y,int xx,int yy);
		//鼠标坐标：m.x,m.y
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE: //鼠标移动
			break;
		case WM_LBUTTONDOWN:
			circle(m.x, m.y, 5);
			break;
		case WM_RBUTTONDOWN:
			rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
			break;
		default:
			break;
		}
	}


	_getch();//等待用户按键：让程序停在这里
	closegraph();

	return 0;
}