#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//�ڱ����ú��������ڴ棬������ʹ�� 
void allcoateSpace(int ** p,int length){
	
	int * arr=(int *)malloc(sizeof(int)*10);
	int i=0;
	for(i=0;i<length;i++){
		arr[i]=i+10;
	}
	*p=arr;
}

void printfArray(int **p,int length){
	int i=0;
	for(i=0;i<length;i++){
		printf("%d\n",(*p)[i]);
	}
} 

//����ط����β�Ϊʵ�εĸ��� 
void freePointer(int * p){
	if(p!=NULL){
		free(p);
		p=NULL;
	}
}

void freePointer01(int ** p){
	if(*p!=NULL){
		free(*p);
		*p=NULL;
	}
} 

void test(){
	int * p=NULL;
	allcoateSpace(&p,10);
	printfArray(&p,10);
	
	//�����ͷ��ͷŷ�ʽ�����p ��ʵ��û���ͷţ����Ұָ�� 
	//freePointer(p);
	//p=NULL; 
	
	freePointer01(&p);
	if(p==NULL){
		printf("%s\n","���ͷ�"); 
	}
} 

int main(){
	test();
}
