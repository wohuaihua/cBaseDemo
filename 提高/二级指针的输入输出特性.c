#include<stdio.h>
#include <string.h>
#include <stdlib.h>


//�������������ڴ棬�����ú���ʹ�� 
void printfArray(int ** p,int length){
	int i=0;
	for(i=0;i<length;i++){
		printf("%d\n",*p[i]);
	}
} 

void test(){
	//�洢��ջ�� 
	int a=10;
	int b=20;
	int c=30;
	int d=40;
	int e=50;
	
	//�ڶ��п����ڴ� 
	int ** p=(int **)malloc(sizeof(int *)*5);
	p[0]=&a;
	p[1]=&b;
	p[2]=&c;
	p[3]=&d;
	p[5]=&e;
	//���p����ָ�룬û��������� 
	printfArray(p,5);
	
	if(p!=NULL){
		free(p);
		p=NULL;
	} 
}

void test2(){
	int *array[5];
	int i=0;
	for(i=0;i<5;i++){
		array[i]=malloc(4);
		*(array[i])=100+i;
	}
	//���array��һ�����飬���Լ������ 
	int lenght=sizeof(array)/sizeof(int*);
	printfArray(array,lenght);
	
	for(i=0;i<lenght;i++){
		if(array[i]!=NULL){
			free(array[i]);
			array[i]=NULL; 
		}
	}
} 

int main(){
	test2();
}
