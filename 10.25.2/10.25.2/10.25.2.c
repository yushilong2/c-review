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
//一维数组作为函数参数传递
void printArr(int arr[10]) 
//void printArr(int arr[10])这种方式也可以，实际还是传递的地址
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
//二维数组作为函数参数传递
void printArr2(int(*arr)[5], int x, int y)
{
	for (int i = 0;i < x;i++)
	{
		for (int j = 0;j < y;j++)
		{
			printf("%d,", arr[i][j]);
		}
		printf("\n");
	}
}
//三维数组
void printArr3(int(*arr)[3][4], int x, int y, int z)
{
	for (int i = 0;i < x;i++)
	{
		for (int j = 0;j < y;j++)
		{
			for (int k = 0;k < z;k++)
				printf("%d,", arr[i][j][k]);
			printf("\n");
		}
	}
}

void showdouble(double* d) 
{
	printf("浮点型：%f\n",*d);
}

//指针作为函数的返回值
//注意：返回的地址必须是可用的，就是没有被释放的
int* test1(int* c) 
{
	*c = 100;
	return c;
}

//数组不能作为函数参数返回

//函数指针：
void show() 
{
	printf("hello\n");
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

	int arr2[4][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	printArr2(arr2, 4, 5);

	int arr3[2][3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	printArr3(arr3, 2, 3, 4);

	double d = 456.789;
	showdouble(&d);
	//当是结构体的时候，实参和形参过大，拷贝效率过低
	//提高效率，使用double*，拷贝永远四个字节
	//实参所占内存字节过大时，可以使用传址方式进行优化，提高效率
	//实参所占内存字节过小，如char型时，使用传值方式更好
	int m = 10;
	int* pm = test1(&m);
	printf("m=%d\n", m);
	//show是一个函数
	printf("show=%d\n", show);//打印的函数指针
	//指针的类型是

	return 0;
}