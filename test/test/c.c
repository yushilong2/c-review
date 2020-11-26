extern int a;
extern int b;
int func(int a,int b)
{
	a = (a + b) * 2;
	return a;
}

int funs(int a, int b)
{
	a = a * b;
	return a;
}