#include<stdio.h>
#include<string.h>
#define MAX 1000

enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
};

//1.��ź��ѵ���Ϣ
struct PeoInfo
{
	char name[20];//����
	int age;//����
	char sex[5];//�Ա�
	char tele[12];//�绰
	char addr[30];//סַ
};

//ͨѶ¼����
struct Contact
{
	struct PeoInfo data[MAX];//���һ����Ϣ
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
};
//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);
//����
void AddContact(struct Contact* ps);
//��ʾ
void ShowContact(const struct Contact* ps);
//ɾ��
void DelContact(struct Contact* ps);
//����
void SearchContact(struct Contact* ps);
//�޸�
void ModifyContact(struct Contact* ps);