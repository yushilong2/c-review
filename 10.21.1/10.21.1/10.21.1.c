#include<stdio.h>
int main() 
{
	int a = 10, b = 20, c = 30;
	printf("a=%d,b=%d,c=%d\n", a, b, c);

	int* pa = &a, * pb = &b, * pc = &c;
	printf("pa=%d,pb=%d,pc=%d\n", pa, pb, pc);

	//1.指针的运算
	//指针+整数=指针
	//指针-整数=指针
	//指针-指针=单位长度
	//在一段连续的内存空间中，数组，动态开辟的内存当中
	//>,<,这两个判断指针的大小，也只有在一段连续的内存空间中比较才有意义
	//==,!=
	int* pd = pa + 10;
	printf("pd=%d\n", pd);

	double d = 45.6;
	double* pdouble = &d;
	printf("pdouble  =%d\n", pdouble);
	printf("pdouble+5=%d\n", pdouble+5);

	char ch = 'A';
	char* pch = &ch;
	printf("pch  =%d\n", pch);
	printf("pch+5=%d\n", pch + 5);

	//实际增加 = 整数 * 指针所指向的类型所占内存大小
	
	printf("pdouble-4=%d\n", pdouble - 4);

	//指针-指针
	printf("pa-pb=%d\n", pa - pb);

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//数组名arr表示，数组的首地址
	printf("arr=%d\n", arr);
	printf("arr[0]的地址=%d\n", &arr[0]);
	//arr的类型：指向int型的指针

	//int* parr = arr;
	printf("arr+1=%d\n", arr + 1);
	printf("arr+2=%d\n", arr + 2);
	printf("arr+3=%d\n", arr + 3);

	printf("&arr[1]=%d\n", arr[1]);
	printf("&arr[2]=%d\n", arr[2]);
	printf("&arr[3]=%d\n", arr[3]);

	//推导：arr+0=arr[0],arr+1=arr[1],arr+2=arr[2],...
	//继续推导：*(arr+0)=arr[0]
	printf("*(arr+0)=%d\n", *(arr + 0));

	//数组的遍历
	for (int i = 0;i < 10;i++) 
	{
		printf("%d,", *(arr + i));
	}
	printf("\n");

	//可以通过指针-指针读出中间有几个元素
	int* parr = arr + 6;
	printf("parr-arr=%d\n",parr - arr);

	//二位数组
	int arr2[4][5] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20}
	};

	for (int i = 0;i < 4;i++) 
	{
		for (int j = 0;j < 5;j++)
		{
			printf("%d,", arr2[i][j]);
		}
		printf("\n");
	}
	//arr2表示二维数组首地址
	//arr2类型：不是指向int型的指针，是一个指向数组的指针
	//可以把二维数组看成一维数组，一维数组里面四个元素是数组
	
	//数组指针：是一个指针
	//指针数组：是一个数组，数组里面存的都是指针
	//arr2是数组指针，指向一个数组

	int(*parr2)[5] = arr2;//现在就定义了一个数组指针,[]里是数组的大小
	printf("arr2+0=%d\n", arr2 + 0);
	printf("arr2+1=%d\n", arr2 + 1);//偏移5*4个字节

	//间接访问
	printf("*（arr2+0）=%d\n", *(arr2 + 0));//得到整个数组,数组名=》arr2[0]
	printf("*（arr2+1）=%d\n", *(arr2 + 1));

	//arr2+0类型是：指向整个一维数组的指针
	//arr2[0]类型是：指向整形的指针
	//*(*(arr2 + 0)+0)=>*(arr2[0]+0)
	//*(arr2+0)+2=>&arr2[0][2]
	//*(*(arr2+0)+2)=>3

	//推导：*(*(arr2+0)+0)=>arr2[0][0]

	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			printf("%d,", *(*(arr2 + i) + j));
		}
		printf("\n");
	}

	//指针和数组的区别：
	int arr3[2][3][4] = { 0,1,2,3 };
	//arr3的类型：是一个指向二维数组的指针 
	int(*parr3)[3][4] = arr3;

	//指针和字符串的关系
	printf("%d\n", "HelloWorld");//这里打印出来的是字符串的首地址，指针
	//这个指针的类型是：char*型
	char* str = "Hello";
	printf("%s\n", str);

	*"HelloWorld";//
	printf("*\"HelloWorld\"=%c\n", *"HelloWorld");
	printf("*(\"HelloWorld\"+1)=%c\n", *("HelloWorld"+1));

	//数组的下标访问和间接访问互相通用

	return 0;
}