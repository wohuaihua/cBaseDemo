#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//ջ����Ҫ���ؾֲ������ĵ�ַ 
int * fun(){
	//aΪ�ֲ���������ջ����������֮�󣬾ֲ������������� 
	int a=10;
	return &a;
}

void test(){
	int *p=fun();
	//����Ѿ�����Ҫ����Ϊa�ĵ�ַ�Ѿ����ͷ��ˣ�����û��Ȩ�޲�������ڴ档 
	//��һ�Σ������������˱��� 
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
