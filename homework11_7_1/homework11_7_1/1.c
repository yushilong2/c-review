#include<stdio.h>
int main() 
{
	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));//10,5

	return 0;
}