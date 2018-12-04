# include<stdio.h>
#include <string.h>
#include <stdlib.h>

//越界 
void test(){
	//后边会加上\0 
	//char buf[3]="abc";
	//printf("%s\n",buf);
}

//指针叠加会不断改变指针的指向
void test1(){
	char * p=(char *)malloc(50);
	char buf[]="abcdef";
	int length=strlen(buf);
	int i=0;
	for(i=0;i<length;i++){
		*p=buf[i];
		p++;
	}
	if(p!=NULL){
		free(p);
		p=NULL;
	}
} 

//正确的方式 
void test2(){
	char *p=(char *)malloc(50);
	char buf[]="abcdef";
	int length=strlen(buf);
	int i=0;
	char *pp=p;
	for(i=0;i<length;i++){
		*pp=buf[i];
		pp++;
	}
	if(p!=NULL){
		free(p);
		p=NULL;
	}
}

//返回局部变量地址 
char * test3(){
	//这是一个局部变量 ，当这个方法结束的时候，存在栈中的变量会被销毁 
	char buf[]="abcdefgh";
	printf("%s\n",buf);
	return buf; 
} 

//同一块内存释放多次，野指针 
void test4(){
	char *p=(char *)malloc(50);
	strcpy(p,"abcdef");
	free(p);
	if(p!=NULL){
		free(p);
	} 
} 

int main(){
	test4();
} 
