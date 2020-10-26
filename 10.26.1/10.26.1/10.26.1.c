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
struct Person //类型名
{
	//结构体成员
	char name[20];//记得打分号
	char sex[4];
	unsigned char age;
	int height;
	float weight;
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
	struct Person* pPerson = &p1;
	//pPerson->height<=>(*pPerson).age
	psay(pPerson);

	return 0;
}