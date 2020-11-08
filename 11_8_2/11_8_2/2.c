#include<stdio.h>
struct S 
{
	int a;
	int b;
};
struct stu 
{
	int num;
	char name[10];
	int age;
};
void fun(struct stu* p) 
{
	printf("%s\n", (*p).name);
	return;
}
int main()
{
	struct S a, * p = &a;
	a.a = 99;
	printf("%d\n", a.a);
	printf("%d\n", (*p).a);
	printf("%d\n", p->a);

	struct stu students[3] =
	{
	{9801,"zhang",20},
	{ 9802,"wang",19 },
	{ 9803,"zhao",18 }
	};
	fun(students + 1);//wang

	//喝汽水，1瓶汽水1元，2个空瓶可以换1瓶汽水，给20元，能够喝到多少汽水
	int money = 20;
	//买回来的汽水
	int total = money;
	int empty = money;
	//换回来的
	while (empty>=2) 
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("total=%d\n", total);
	return 0;
}