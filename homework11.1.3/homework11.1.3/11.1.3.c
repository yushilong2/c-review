//����Ҫ���д���򣬼�������2/1+3/2+5/3+8/5+������ǰN��֮�͡�ע������дӵ�2����ÿһ��ķ�����ǰһ��������ĸ֮�ͣ���ĸ��ǰһ��ķ��ӡ�
//�����ʽ��������һ���и���һ��������N��
//�����ʽ����һ����������ֺ͵�ֵ����ȷ��С�����2λ����Ŀ��֤������������˫���ȷ�Χ
#include<stdio.h>
int main() 
{
	int n;
	double dividend, divisor;//ֵ�ܴ󣬲�����int
	double sum = 0.0;
	int i;
	double t;
	scanf("%d", &n);
	//n=20000;
	dividend = 2;
	divisor = 1;
	for (i = 1;i <= n;i++) 
	{
		sum += dividend / divisor;
		t = dividend;
		dividend = dividend + divisor;
		divisor = t;
	}
	printf("%.2f\n", sum);
	return 0;
}