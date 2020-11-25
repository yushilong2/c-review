#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

//������
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
//�ߵ�����
struct LineTool
{
	int size;//��ϸ
	COLORREF color;//��ɫ
	Point begPos;//��ʼλ��
	bool isDown;//�������Ƿ��µı��
	LineTool(int lineSize, COLORREF lineColor)
	{
		size = lineSize;
		color = lineColor;
		isDown = false;//û�а���
	}
	//��괦��
	void callMouse(MOUSEMSG m)
	{
		//��������Ĵ���
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			isDown = true;
			begPos = Point(m.x, m.y);
		}
		//�������Ĵ���
		if (m.uMsg == WM_LBUTTONUP)
		{
			isDown = false;
		}
		//˫������������
		if (m.uMsg == WM_MOUSEMOVE && isDown)
		{
			setlinestyle(PS_ENDCAP_ROUND, size);
			setlinecolor(color);
			line(begPos.x, begPos.y, m.x, m.y);
		}
		//ÿ�λ��߽�����
		begPos = Point(m.x, m.y);
		//���Ч��
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
		//���ڰ�����ȥ����
		if (_kbhit())
		{
			char userKey = _getch();//��ȡ����
			//������ֵ
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
				MessageBox(hwnd, "����ɹ�", "����ɹ�", MB_OK);
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