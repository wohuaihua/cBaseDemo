# include<stdio.h>
#include <string.h>
#include <stdlib.h>

//Խ�� 
void test(){
	//��߻����\0 
	//char buf[3]="abc";
	//printf("%s\n",buf);
}

//ָ����ӻ᲻�ϸı�ָ���ָ��
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

//��ȷ�ķ�ʽ 
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

//���ؾֲ�������ַ 
char * test3(){
	//����һ���ֲ����� �����������������ʱ�򣬴���ջ�еı����ᱻ���� 
	char buf[]="abcdefgh";
	printf("%s\n",buf);
	return buf; 
} 

//ͬһ���ڴ��ͷŶ�Σ�Ұָ�� 
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
