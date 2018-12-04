#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//栈，不要返回局部变量的地址 
int * fun(){
	//a为局部变量，入栈，方法结束之后，局部变量被消除。 
	int a=10;
	return &a;
}

void test(){
	int *p=fun();
	//结果已经不重要，因为a的地址已经被释放了，我们没有权限操作这个内存。 
	//第一次，编译器进行了保留 
	printf("%d\n",*p);
	printf("%d\n",*p);
	 
}

char * getString(){
	char arr[]="Hello World";
	return arr; 
} 

void test2(){
	char *p=NULL;
	p=getString();
	printf("%s\n",*p);
}

int main(){
	//test();
	test2(); 
} 
