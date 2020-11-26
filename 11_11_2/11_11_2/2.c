#include<stdio.h>
#include<stdlib.h>
int main()
{
	//申请空间
	int* p = (int*)malloc(10 * sizeof(int));
	//使用空间
	//********
	//释放空间
	free(p);
	//free完之后，p指针里面依旧存着地址
	p = NULL;

	char str1[] = "hello yu.";
	char str2[] = "hello yu.";
	char* str3 = "hello yu.";
	char* str4 = "hello yu.";
	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");
	//str1 and str2 are not same
	//str3 and str4 are same

	int a[5] = { 5,4,3,2,1 };
	//5 4 3 2 1
	int* ptr = (int*)(&a + 1);//ptr指向数组后面
	printf("%d,%d\n", *(a + 1), *(ptr - 1));//4,1

	int aa[2][5] = { 10,39,8,7,6,5,4,3,2,1 };
	int* ptr1 = (int*)(&aa + 1);//ptr1指向二维数组后面
	int* ptr2 = (int*)(*(aa)+1);//ptr2指向第二行地址//*(aa+1)=aa[1]
	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));//1,6

	return 0;
}