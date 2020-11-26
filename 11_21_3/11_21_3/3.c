#include<stdio.h>

struct S
{
	int n;
	float score;
	char arr[10];
};

int main()
{
	struct S s = { 100,3.14f,"bit" };
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		return 0;
	}
	//格式化的形式写文件
	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
	//格式化的输入数据
	fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);
	printf("%d %f %s\n", s.n, s.score, s.arr);
	//关闭
	fclose(pf);
	pf = NULL;

	//scanf/printf是针对标准输入流/标准输出流的格式化输入/输出语句
	//fscanf/fprintf是针对所有输入流/所有输出流的格式化输入/输出语句
	//sscanf是从字符串中读取格式化的数据，sprintf是把格式化的数据输出成(存储到)字符串
	struct S s2 = { 100,3.14f,"abcdef" };
	struct S tmp = { 0 };
	char buf[1024] = { 0 };
	//把格式化的数据转换成字符串存储到buf
	sprintf(buf, "%d %f %s", s2.n, s2.score, s2.arr);
	//从buf中读取格式化的数据到tmp中
	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
	printf("%d %f %s\n", tmp.n, tmp.score, tmp.arr);

	return 0;
}