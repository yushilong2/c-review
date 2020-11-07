#include<stdio.h>
int main()
{
	char* a[] = { "work","at","school" };//存的是三个字符串首字母的地址 
	char** pa = a;
	pa++;
	printf("%s\n", *pa);//at

	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);//POINT
	printf("%s\n", *-- * ++cpp + 3);//ER
	printf("%s\n", *cpp[-2] + 3);//ST
	printf("%s\n", cpp[-1][-1] + 1);//EW

	return 0;
}