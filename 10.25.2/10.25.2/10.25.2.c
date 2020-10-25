#include<stdio.h>
//实现两个变量a和b的值
void swap(int a, int b) 
{
	int temp = a;
	a = b;
	b = temp;
	printf("a=%d,b=%d\n", a, b);
}
void s(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}
void display(char* str)
{
	printf("%s\n", str);
}
//传递一个数组
void printArr(int arr[10]) 
{
	for (int i = 0;i < 10;i++)
	{
		printf("%d,", arr[i]);
	}
	printf("\n");
	printf("arr的大小：%d\n", sizeof(arr));//这里打印出来又是多少
	//数组作为函数参数传递的时候，传递的首地址，而不是整个数组了，已经变成了地址
	//不知道数组有多少个元素
}

int main() 
{
	int a = 10, b = 20, c = 30;
	int* pa = &a, * pb = &b, * pc = &c;
	printf("pa=%d,pb=%d,pc=%d\n", pa, pb, pc);
	//想交换两个变量a和b的值
	printf("a=%d,b=%d,c=%d\n", a, b, c);
	swap(a, b);
	printf("a=%d,b=%d,c=%d\n", a, b, c);
	s(&a, &b);
	printf("a=%d,b=%d,c=%d\n", a, b, c);
	//传值和传址
	//其实不管传值还是传址都是传递的一份拷贝
	display("HelloWorld");

	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	printArr(arr);//arr传递的是一个地址
	printf("arr的大小：%d\n", sizeof(arr));//这里打印出来是多少

	return 0;
}