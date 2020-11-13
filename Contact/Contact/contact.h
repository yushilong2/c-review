#include<stdio.h>
#include<string.h>
#define MAX 1000
//1.存放好友的信息
struct PeoInfo
{
	char name[20];//名字
	int age;//年龄
	char sex[5];//性别
	char tele[12];//电话
	char addr[30];//住址
};

//通讯录类型
struct Contact
{
	struct PeoInfo data[MAX];//存放一个信息
	int size;//记录当前已经有的元素个数
};

void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);