#include<stdio.h>
#include<string.h>
void GetMemory(char** p)
{
	*p = (char*)malloc(100);
}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	//�������
//	//��������ڴ�й©������
//	//str��ֵ����ʽ��p
//	//p��GetMemory�������βΣ�ֻ�ܺ����ڲ���Ч
//	//��GetMemory��������֮�󣬶�̬�����ڴ���δ�ͷŲ����޷��ҵ������Ի�����ڲ�й©
//	printf(str);
//}
void Test(void)
{
	char* str = NULL;
	GetMemory(&str);
	strcpy(str, "hello world");
	printf(str);
	free(str);
	str = NULL;
}

int main()
{
	Test();
	char* str = "abcdef";
	printf("%s\n", str);
	printf(str);
	printf("abcdef");

	return 0;
}