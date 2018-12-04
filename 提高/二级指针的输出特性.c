#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//在被调用函数分配内存，主函数使用 
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

//这个地方的形参为实参的副本 
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
	
	//这种释放释放方式会造成p ，实参没有释放，变成野指针 
	//freePointer(p);
	//p=NULL; 
	
	freePointer01(&p);
	if(p==NULL){
		printf("%s\n","已释放"); 
	}
} 

int main(){
	test();
}
