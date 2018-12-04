#include<stdio.h>
#include <string.h>
#include <stdlib.h>


//主调函数分配内存，被调用函数使用 
void printfArray(int ** p,int length){
	int i=0;
	for(i=0;i<length;i++){
		printf("%d\n",*p[i]);
	}
} 

void test(){
	//存储在栈中 
	int a=10;
	int b=20;
	int c=30;
	int d=40;
	int e=50;
	
	//在堆中开辟内存 
	int ** p=(int **)malloc(sizeof(int *)*5);
	p[0]=&a;
	p[1]=&b;
	p[2]=&c;
	p[3]=&d;
	p[5]=&e;
	//这个p代表指针，没法计算个数 
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
	//这个array是一个数组，可以计算个数 
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
