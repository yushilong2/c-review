#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#define MAX 1000
#define DEFAULT_SZ 3

enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
};

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
	struct PeoInfo* data;//存放一个信息
	int size;//记录当前已经有的元素个数
	int capacity;//当前通讯录的最大容量
};
//初始化通讯录
void InitContact(struct Contact* ps);
//增加
void AddContact(struct Contact* ps);
//显示
void ShowContact(const struct Contact* ps);
//删除
void DelContact(struct Contact* ps);
//查找
void SearchContact(struct Contact* ps);
//修改
void ModifyContact(struct Contact* ps);
//释放
void DestroyContact(struct Contact* ps);