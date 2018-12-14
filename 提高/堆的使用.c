#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
*	C99标志开始才支持 for(int i=0;i<5;i++) 这种方式for循环 
*/
 
int * getSpace(){
	//p指向分配空间的首地址 
	int *p=malloc(sizeof(int)*5);
	if(p==NULL){
		return NULL;
	}
	
	int i;
	for(i=0;i<5;i++){
		p[i]=i+100;
	}
	return p; 
} 


void test(){
	int *p=getSpace();
	int i;
	for(i=0;i<5;i++){
		printf("%d\n",p[i]);
	}
	free(p);
	//防止野指针 
	p=NULL; 
}

int main(){
	test();
	system("pause");
}
