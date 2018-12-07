#include <stdio.h>
#include <stdlib.h>
 
int fun1()
{
 printf("this is fun1 call\n");
 return 1;
}
 
void fun2(int k, char c)
{
 printf("this is fun2 call:%d %c\n", k, c);
}
 
int main()
{
	int (*pfun1)() = NULL;
	void (*pfun2)(int, char) = NULL;
	int a,b;
	pfun1 = fun1; //第一种赋值方法
	a = pfun1();  //第一种调用方法（推荐）
	printf("%d\n",a);
	b = (*pfun1)();//第二种调用方法
	printf("%d\n",b);
	
	pfun2 = &fun2;//第二种赋值方法（推荐，因为和其他数据指针赋值方法一致）
	pfun2(1,'a');
	(*pfun2)(2,'b');
	return 0;
}
