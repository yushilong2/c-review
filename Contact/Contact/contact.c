#include"contact.h"
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//设置通讯录最初只有0个元素
}
//2.增加好友信息
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别：");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
	}
}

static int FindByName(const struct Contact* ps, char name[20])
{
	int i = 0;
	for (i = 0;i < ps->size;i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;//找不到
}

//3.删除指定好友信息
void DelContact(struct Contact* ps)
{
	char name[20];
	printf("请输入要删除人的名字：");
	scanf("%s", name);
	//1.查找
	int i = FindByName(ps, name);
	//2.删除
	if (i==-1)
	{
		printf("找不到该人\n");
	}
	else
	{
		int j = 0;
		for (j = i;j < ps->size - 1;j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}
//4.查找好友信息
void SearchContact(const struct Contact* ps)
{
	char name[20];
	printf("请输入要查找人的名字：");
	scanf("%s", name);
	//1.查找
	int i = FindByName(ps, name);
	if (i==-1)
	{
		printf("找不到该人\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].tele,
			ps->data[i].addr);
	}
}
//5.修改好友信息
void ModifyContact(struct Contact* ps)
{
	char name[20];
	printf("请输入要修改人的名字：");
	scanf("%s", name);
	//1.查找
	int i = FindByName(ps, name);
	if (i == -1)
	{
		printf("找不到该人\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[i].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[i].age));
		printf("请输入性别：");
		scanf("%s", ps->data[i].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[i].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[i].addr);
		printf("修改完成\n");
	}
}
//6.打印好友信息
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0;i < ps->size;i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}