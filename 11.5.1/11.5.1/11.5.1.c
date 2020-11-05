#include<stdio.h>
#include<string.h>
int main()
{
	//char arr[] = { 'a','b','c','d','e','f' };
	char arr[] = "abcdef";

	printf("%d\n", sizeof(arr));//sizeof(arr)计算的是数组的大小，单位是字节：7
	printf("%d\n", sizeof(arr + 0));//arr+0是首元素的地址，sizeof(arr+0)计算的是地址的大小：4/8
	printf("%d\n", sizeof(*arr));//*arr是首元素，sizeof(*arr)计算的是首元素的大小：1
	printf("%d\n", sizeof(arr[1]));//arr[1]是第二个元素，sizeof(arr[1])计算的是第二个元素的大小：1
	printf("%d\n", sizeof(&arr));//&arr虽然是数组的地址，但也是地址：4/8
	printf("%d\n", sizeof(&arr + 1));//&arr+1数组地址加一,是跳过整个数组后的地址：4/8
	printf("%d\n", sizeof(&arr[0] + 1));//&arr[0]+1第一个元素的地址加一，是第二个元素的地址：4/8

	printf("%d\n", strlen(arr));//求字符串长度，没有'\0'：6
	printf("%d\n", strlen(arr + 0));//从首元素开始：6
	//printf("%d\n", strlen(*arr));//报错，传的是字符a，strlen把97当作地址访问，非法访问内存
	//printf("%d\n", strlen(arr[1]));//同上
	printf("%d\n", strlen(&arr));//&arr - 数组的地址 - 数组指针 char(*p)[7]=&arr；会有警告
	printf("%d\n", strlen(&arr + 1));// 同上，因为是数组后，所以结果随机
	printf("%d\n", strlen(&arr[0] + 1));//b的地址，所以从b往后算：5

	char *p = "abcdef";
	//把常量字符串abcdef\0的首元素a的地址放进p里面
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p + 1));
	printf("%d\n", sizeof(*p));
	printf("%d\n", sizeof(p[0]));
	printf("%d\n", sizeof(&p));
	printf("%d\n", sizeof(&p + 1));
	printf("%d\n", sizeof(&p[0] + 1));

	/*printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p + 1));
	printf("%d\n", sizeof(*p));
	printf("%d\n", sizeof(p[0]));
	printf("%d\n", sizeof(&p));
	printf("%d\n", sizeof(&p + 1));
	printf("%d\n", sizeof(&p[0] + 1));*/

	return 0;
}