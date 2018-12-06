#include<stdio.h>
#include <string.h>
#include <stdlib.h>


void test(){
	int arr[5]={1,2,3,4,5};
	typedef int(Array)[5];
	Array * arrP=&arr;
	int i=0;
	for(i=0;i<5;i++){
		printf("%d\n",(* arrP)[i]);
	}
	 
} 

void test01(){
	int arr[5]={1,2,3,4,5};
	typedef int(* Array)[5];
	Array arrP=&arr;
	int i=0;
	for(i=0;i<5;i++){
		printf("%d\n",(* arrP)[i]);
	}
}

void test02(){
	int arr[5]={1,2,3,4,5};
	int (*arrP)[5]=&arr;
	int i=0;
	for(i=0;i<5;i++){
		printf("%d\n",(* arrP)[i]);
	}
}

int main(){
	test02();
} 
