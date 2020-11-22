#include<stdio.h>
#pragma pack(4)//编译选项，表示4字节对齐
typedef struct
{
	int a;//0-3 4
	char b;//4 1
	//5
	short c;//6-7 2
	short d;//8-9 2
	//10-11
}AA_t;//12个字节

//4字节对齐
struct A
{
	int a;//0-3 4
	short b;//4-5 2
	//6-7 2
	int c;//8-11 4
	char d;//12 1
	//13-15 3
};//16
struct B
{
	int a;//0-3 4
	short b;//4-5 2
	char c;//6 1
	//7 1
	int d;//8-11 4
};//12

struct tagTest1
{
	short a;//0-1 2
	char d;//2 1
	//3 1
	long b;//4-7 4
	long c;//8-11 4
};//12
struct tagTest2
{
	long b;//0-3 4
	short c;//4-5 2
	char d;//6 1
	//7 1
	long a;//8-11 4
};//12
struct tagTest3
{
	short c;//0-1 2
	//2-3 2
	long b;//4-7 4
	char d;//8 1
	//9-11 3
	long a;//12-15 4
};//16

struct tagTest1 stT1;
struct tagTest2 stT2;
struct tagTest3 stT3;


int main()
{
	printf("%d\n", sizeof(AA_t));
	printf("%d\n", sizeof(struct A));
	printf("%d\n", sizeof(struct B));
	printf("%d %d %d\n", sizeof(stT1), sizeof(stT2), sizeof(stT3));
	return 0;
}