#include<stdio.h>
#include<string.h>
int main()
{
	unsigned char a = 200;//一个字节，无符号，范围：0~255
	unsigned char b = 100;
	unsigned char c = 0;
	c = a + b;//整形提升
	//a+b=100101100
	//c八位：00101100
	printf("%d %d\n", a + b, c);//300,44
	
	unsigned int aa = 0x1234;
	unsigned char bb = *(unsigned char*)&aa;
	//小端：34 12 00 00—>34
	//大端：00 00 12 34—>00
	printf("%d\n", bb);//大端：00，小端：52

	//-128——>127
	char d[1000] = { 0 };
	int i = 0;
	for (i = 0;i < 1000;i++)
	{
		d[i] = -1 - i;
	}
	printf("%d\n", strlen(d));//255
	//-1—>-128—>127—>1



	return 0;
}