#include<stdio.h>
#include<string.h>
int is_left_move(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
	{
		return 0;
	}
	//1.��str1�ַ�����׷��һ��str1�ַ���
	//2.�ж�str2ָ����ַ����Ƿ���str1ָ����ַ������Ӵ�
	//strcat(str1, str1);//�Լ����Լ�׷�ӵ�ʱ������
	strncat(str1, str1, len1);//abcdefabcdef
	//strstr//���Ӵ���
	char* ret = strstr(str1, str2);
	if (ret == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	char arr1[30] = "abcdef";
	char arr2[] = "cdefab";
	char arr3[] = "cdef";
	int ret1 = is_left_move(arr1, arr2);
	int ret2 = is_left_move(arr1, arr3);
	if (ret1 == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	if (ret2 == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}