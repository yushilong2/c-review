#include"contact.h"

void menu()
{
	printf("*********************************\n");
	printf("*** 1.add               2.del ***\n");
	printf("*** 3.search            4.modify*\n");
	printf("*** 5.show              0.exit***\n");
	printf("*********************************\n");
}

void main() 
{
	int input = 0;
	//创建通讯录
	struct Contact con;//存放一千个人的信息
	//初始化通讯录
	InitContact(&con);
	do 
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}