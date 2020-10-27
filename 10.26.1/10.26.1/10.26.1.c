#include<stdio.h>
//枚举：类似于define宏定义
enum Hero
{
	Guanyu=1,
	Zhangfei=2,
	Liubei=3
};//里面都是整形值
//可以给部分枚举给值，也可以不给值
//全部不给值默认从0开始
enum Color { red, green=131, blue }color;
//比宏定义更方便管理

//结构体

//struct Person //类型名
//{
//	//结构体成员
//	char name[20];//记得打分号
//	char sex[4];
//	unsigned char age;
//	int height;
//	float weight;
//};

//typrdef的第一种方式
/*typedef struct _Person //类型名
{
	//结构体成员
	char name[20];//记得打分号
	char sex[4];
	unsigned char age;
	int height;
	float weight;
}Person;*/
//第二种方式
//typedef struct _person Person;

typedef struct Person //类型名
{
	//结构体成员
	char name[20];//记得打分号
	char sex[4];
	unsigned char age;
	int height;
	float weight;
}Person,*PPerson;
//Person,PPerson都是类型名；PPerson是Person*

//节点
//结构体自引用
//struct Node
//{
//	int data;//数据域
//	struct Node node;
//};
//失败原因，无法确定Node类型的大小
//正确用法，放指针
struct Node
{
	int data;//数据域
	struct Node* next;//指针域
};

//不完整声明
struct B;

struct A
{
	int num;
	struct B *b;//不带指针的话，因为B在下面，程序从上往下执行，无法确认B多大，也可以给个不完整声明
};

struct B 
{
	int num;
};

struct Test 
{
	char ch;
	short s;
	int n;
};
struct Test1
{
	char ch;
	int n;
	short s;
};
struct Test2
{
	char str[10];
	char ch;
	int n;
	short s;
};

//人说话
void say(struct Person p) 
{
	printf("姓名：%s,性别：%s,年龄：%d,身高：%d,体重：%.2f\n", p.name, p.sex, p.age, p.height, p.weight);
}
void psay(struct Person *p)
{
	printf("姓名：%s,性别：%s,年龄：%d,身高：%d,体重：%.2f\n", p->name, p->sex, p->age, p->height, p->weight);
}

int main() 
{
	enum Hero hero = Zhangfei;
	printf("hero=%d\n", hero);

	color = red;
	printf("color=%d\n", color);
	color = blue;
	printf("color=%d\n", color);

	//定义并且初始化
	struct Person p1 = { "关羽","男",30,176,90.0f };
	//可以只给部分成员初始化,后面全部为0
	struct Person p2 = { "刘备","男",35 };
	//使用结构体
	//一个结构体可以赋值给另外一个结构体
	p1.age = 31;//name不能改，因为name和sex都是数组名，不能赋值
	//可以这样
	//p1.name[0]='s';
	//p1.name[1]='e';
	//也可以用字符串复制函数
	//strcpy(p1.name,"张飞")
	printf("姓名：%s,性别：%s,年龄：%d\n", p1.name, p1.sex, p1.age);
	say(p2);
	//可以定义结构体数组
	struct Person arr[2] = { p1,p2 };
	say(arr[0]);

	//一个指针可以指向一个结构体
	PPerson pp = &p1;
	//pPerson->height<=>(*pPerson).age
	psay(pp);
	psay(&p1);

	//传指针和传值得区别：参数传递的都是一份拷贝
	//传指针的效率比较高，而且传指针可以修改，传值传的形参，实参不会改变

	//链表
	struct Node node1, node2;
	node1.data = 45;
	node1.next = &node2;
	
	node1.next->data = 90;

	printf("%d\n", sizeof(struct A));

	printf("%d\n", sizeof(struct Test));//8,不是7个字节，原因：边界对齐，按照最大的内对齐
	//char和short小于int四个字节，char向short对齐，char和short与int对齐，所以答案是8
	//内存的对齐按排布的顺序，顺序不同，内存不同
	printf("%d\n", sizeof(struct Test1));//答案12
	//char向int对齐,char+3，short向int对齐，short+2
	//并不是单纯的前后相加对齐
	printf("%d\n", sizeof(struct Test2));//20
	//str加char向12对齐，加int向16字节对齐，加short4字节，向20字节对齐
	////对齐是2的倍数，有利于寻址的速度

	return 0;
}