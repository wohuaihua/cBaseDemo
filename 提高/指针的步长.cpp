#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//指针的步长
//指针变量+1之后，跳跃的字节书香
void test1() {
	char *p=NULL;
	printf("%d\n",p);
	printf("%d\n",p+1);

	double *pp=NULL;
	printf("%d\n",pp);
	printf("%d\n",pp+1);
}

//解引用时，取的字节数 
void test2(){
	char buf[1024]={0};
	int a=1000;
	memcpy(buf+1,&a,sizeof(int));
	char *p=buf;
	printf("%d\n",*(int*)(p+1)); 
}

struct Person{
	char a;
	int b;
	char buf[64];
	int d;
}; 

void test3(){
	struct Person p={'a',1000,"abcdefg",1001};
	p.d=1002;
	printf("%d\n",p.d);
}


main() {
	test3();
}
