#include<stdio.h>

void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int move(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		//´Ó×ó±ßÕÒÅ¼Êý
		while ((arr[left] % 2 == 1) && (left < right))
		{
			left++;
		}
		//´ÓÓÒ±ßÕÒÆæÊý
		while ((arr[right] % 2 == 0) && (left < right))
		{
			right--;
		}
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
	}
}

int main() 
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	move(arr, sz);
	print(arr, sz);

	return 0;
}