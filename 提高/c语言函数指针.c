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
	pfun1 = fun1; //��һ�ָ�ֵ����
	a = pfun1();  //��һ�ֵ��÷������Ƽ���
	printf("%d\n",a);
	b = (*pfun1)();//�ڶ��ֵ��÷���
	printf("%d\n",b);
	
	pfun2 = &fun2;//�ڶ��ָ�ֵ�������Ƽ�����Ϊ����������ָ�븳ֵ����һ�£�
	pfun2(1,'a');
	(*pfun2)(2,'b');
	return 0;
}
