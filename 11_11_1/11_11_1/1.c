#include<stdio.h>
int main() 
{
	//a：b第二，我第三
	//b：我第二，e第四
	//c：我第一，d第二
	//d：c第五，我第三
	//e：我第四，a第一
	//每个人说的话有一半是对的
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1;a <= 5;a++)
	{
		for (b = 1;b <= 5;b++)
		{
			for (c = 1;c <= 5;c++)
			{
				for (d = 1;d <= 5;d++)
				{
					for (e = 1;e <= 5;e++)
					{
						if (((b == 2) + (a == 3) == 1) 
						&& ((b == 2) + (e == 4) == 1) 
						&& ((c == 1) + (d == 2) == 1) 
						&& ((c == 5) + (d == 3) == 1) 
						&& ((e == 4) + (a == 1) == 1)) 
						{
							if (a * b * c * d * e == 120)//过滤
								printf("a：%d，b：%d，c：%d，d：%d，e：%d\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}

	return 0;
}