#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

//描述点
struct Point 
{
	int x;
	int y;
	Point()
	{
		x = -1;
		y = -1;
	}
	Point(int xx, int yy)
	{
		x = xx;
		y = yy;
	}
};
//线的属性
struct LineTool
{
	int size;//粗细
	COLORREF color;//颜色
	Point begPos;//起始位置
	bool isDown;//鼠标左键是否按下的标记
	LineTool(int lineSize, COLORREF lineColor)
	{
		size = lineSize;
		color = lineColor;
		isDown = false;//没有按下
	}
	//鼠标处理
	void callMouse(MOUSEMSG m)
	{
		//按下左键的处理
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			isDown = true;
			begPos = Point(m.x, m.y);
		}
		//左键弹起的处理
		if (m.uMsg == WM_LBUTTONUP)
		{
			isDown = false;
		}
		//双键动作的描述
		if (m.uMsg == WM_MOUSEMOVE && isDown)
		{
			setlinestyle(PS_ENDCAP_ROUND, size);
			setlinecolor(color);
			line(begPos.x, begPos.y, m.x, m.y);
		}
		//每次画线结束后
		begPos = Point(m.x, m.y);
		//清除效果
		if (m.uMsg == WM_RBUTTONDOWN)
		{
			setbkcolor(WHITE);
			cleardevice();
		}
	}
};

int main()
{
	HWND hwnd = initgraph(800, 600);
	setbkcolor(WHITE);
	cleardevice();
	LineTool* pLine = new LineTool(5, BLACK);
	while (1) 
	{
		while (MouseHit())
		{
			MOUSEMSG m = GetMouseMsg();
			pLine->callMouse(m);
		}
		//存在按键才去处理
		if (_kbhit())
		{
			char userKey = _getch();//获取按键
			//按键的值
			if (userKey == '+')
			{
				pLine->size++;
			}
			if (userKey == '-')
			{
				pLine->size--;
			}
			if (userKey == '\r')
			{
				saveimage("YU.bmp");
				MessageBox(hwnd, "保存成功", "保存成功", MB_OK);
				break;
			}
		}
	}
	delete pLine;
	pLine = NULL;
	_getch();
	closegraph();

	return 0;
}