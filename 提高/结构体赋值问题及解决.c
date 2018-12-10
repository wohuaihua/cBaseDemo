#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//结构体的赋值问题 

struct Person{
	char * name;
	int age;
};

void test(){
	//栈上创建对象 
	struct Person p1={
		"p1 name",
		18
	};
	struct Person p2={
		"p2 name",
		20
	};
	//逐字节复制 , 浅拷贝 
	p1=p2;
	printf("%s,%d\n",p1.name,p1.age);
	printf("%s,%d\n",p2.name,p2.age);
}

void test01(){
	struct Person p1;
	p1.age=18;
	//讲数据放到堆区上 
	p1.name=malloc(sizeof(char)*64);
	strcpy(p1.name,"p1 name"); 
	printf("%s,%d\n",p1.name,p1.age);
	if(p1.name!=NULL){
		free(p1.name);
		p1.name=NULL;
	}
} 

void test02(){
	struct Person p1; 
	p1.age=18;
	p1.name=malloc(sizeof(char)*64);
	strcpy(p1.name,"p1 name"); 
	
	struct Person p2; 
	p2.age=20;
	p2.name=malloc(sizeof(char)*128);
	strcpy(p2.name,"p2 name");
	
	p1=p2;
	printf("%s,%d\n",p1.name,p1.age);
	printf("%s,%d\n",p2.name,p2.age);
	
	//由于p1=p2,p1.name的值为p2.name的值,name为一个地址，下面代码会重新释放2次 name这个地址 
	if(p1.name!=NULL){
		free(p1.name);
		p1.name=NULL;
	}
	if(p2.name!=NULL){
		free(p2.name);
		p2.name=NULL;
	}
}

void test03(){
	struct Person p1; 
	p1.age=18;
	p1.name=malloc(sizeof(char)*64);
	strcpy(p1.name,"p1 name"); 
	
	struct Person p2; 
	p2.age=20;
	p2.name=malloc(sizeof(char)*128);
	strcpy(p2.name,"p2 name");
	
	//手动实现深拷贝
	if(p1.name!=NULL){
		free(p1.name);
		p1.name=NULL;
	}
	p1.name=malloc(sizeof(p2.name));
	strcpy(p1.name,p2.name);
	p1.age=p2.age;
	printf("%s,%d\n",p1.name,p1.age);
	printf("%s,%d\n",p2.name,p2.age);
	//手动释放内存 
	if(p1.name!=NULL){
		free(p1.name);
		p1.name=NULL;
	}
	if(p2.name!=NULL){
		free(p2.name);
		p2.name=NULL;
	}	 
} 

int main(){
	test03();
} 
