#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
/*
* ����ͼ�λ�����
* 1.����ܹ�����������������ڣ�����ʲô��
* ���꣬������Ҽ�--->ֵ
* �ص㲻�����ֵ��������δ洢���ֵ����λ�ȡ���ֵ
* C���Զ������������ ��������
* MOUSEMSG--->����
* GetMouseMsg--->��ȡ������
* �����������ֵ����Ϊ�������ж���
* m.uMsg������������������
* �������ۣ�
* L:left ��
* R:right ��
* button:��ť
* down:��
* WM_LBUTTONDOWN;
* WM_MOUSEMOVE
*/

int main()
{
	initgraph(800, 600);
	MOUSEMSG m;//������ֵ
	while (1)
	{
		m = GetMouseMsg();
		//�����Բ �Ҽ�����
		//��Բ��circle(int x,int y,int r);
		//������rectangle(int x,int y,int xx,int yy);
		//���ߣ�line(int x,int y,int xx,int yy);
		//������꣺m.x,m.y
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE: //����ƶ�
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


	_getch();//�ȴ��û��������ó���ͣ������
	closegraph();

	return 0;
}