#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void testCalloc(){
	int * p=(int *)malloc(sizeof(int)*10);
	for(int i=0;i<10;i++){
		printf("%d\n",p[i]);
	}
	if(p!=NULL){
		free(p);
		p=NULL;
	}
	
	printf("%s\n","------calloc------");
	p=(int *)calloc(10,sizeof(int));
		for(int i=0;i<10;i++){
		printf("%d\n",p[i]);
	}
	if(p!=NULL){
		free(p);
		p=NULL;
	}
}

void testRealloc(){
	int * p=(int *)malloc(sizeof(int)*10);
	printf("%d\n",p);
	p=(int *)realloc(p,sizeof(int)*20); 
	printf("%d\n",p);
	for(int i=0;i<11;i++){
		p[i]=i;	
	}
	for(int i=0;i<11;i++){
		printf("%d\n",p[i]);
	}
	printf("%s\n","-------------------------");
	//realloc不会初始化内存 
	for(int i=0;i<20;i++){
		printf("%d\n",p[i]);
	}
	if(p!=NULL){
		free(p);
		p=NULL;
	}
} 

int main(){
	testRealloc();
} 
