//��a��������
//������������a��n��a�ķ�Χ��[0,9]��n�ķ�Χ��[1,8]��������֮��S=a+aa+aaa+����+aaa...a(n��a)��
//�����ʽ��������һ���и��������������Ⱥ��ʾa��n��
//�����ʽ����һ�������Ҫ�������֮��
#include<stdio.h>
int main() 
{
	int a, n;
	scanf("%d %d", &a, &n);
	int sum = 0;
	int i;
	int t = 0;
	for (i = 0;i < n;i++)
	{
		t = t * 10 + a;
		sum += t;
	}
	printf("%d\n", sum);

	return 0;
}