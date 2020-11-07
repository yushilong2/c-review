#include<stdio.h>
#include<string.h>
#include<assert.h>

void reverse(char* str)
{
	assert(str);
	int len = strlen(str);
	char* left = str;
	char* right = str + len - 1;
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	unsigned long pulArray[] = { 6,7,8,9,10 };
	unsigned long* pulPtr;
	pulPtr = pulArray;
	*(pulPtr + 3) += 3;//9+3
	printf("%d,%d\n", *pulPtr, *(pulPtr + 3));//6,12

	char arr[256] = { 0 };
	gets(arr);//读取一行
	//逆序函数
	reverse(arr);
	printf("%s\n", arr);

	int a = 0;
	int n = 0;
	scanf("%d%d", &a, &n);
	int sum = 0;
	int i = 0;
	int ret = 0;
	for (i = 0;i < n;i++)
	{
		ret = ret * 10 + a;
		sum += ret;
	}
	printf("%d\n", sum);

	return 0;
}