#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//�ṹ��ĸ�ֵ���� 

struct Person{
	char * name;
	int age;
};

void test(){
	//ջ�ϴ������� 
	struct Person p1={
		"p1 name",
		18
	};
	struct Person p2={
		"p2 name",
		20
	};
	//���ֽڸ��� , ǳ���� 
	p1=p2;
	printf("%s,%d\n",p1.name,p1.age);
	printf("%s,%d\n",p2.name,p2.age);
}

void test01(){
	struct Person p1;
	p1.age=18;
	//�����ݷŵ������� 
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
	
	//����p1=p2,p1.name��ֵΪp2.name��ֵ,nameΪһ����ַ���������������ͷ�2�� name�����ַ 
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
	
	//�ֶ�ʵ�����
	if(p1.name!=NULL){
		free(p1.name);
		p1.name=NULL;
	}
	p1.name=malloc(sizeof(p2.name));
	strcpy(p1.name,p2.name);
	p1.age=p2.age;
	printf("%s,%d\n",p1.name,p1.age);
	printf("%s,%d\n",p2.name,p2.age);
	//�ֶ��ͷ��ڴ� 
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
