#include<stdio.h>
#include <string.h>
#include <stdlib.h>


struct Teacher{
	char * name;
	char ** students;
};

struct Teacher ** allocateSpace(){
	struct Teacher ** p=malloc(sizeof(struct Teacher *)*3);
	printf("%d\n",p);
	int i;
	for(i=0;i<3;i++){
		printf("%d\n",p+i); 
		//指针的 p+i 与  p[i] 是不一样的  ，p[i]代表 *(p+i) ,p+i代表指针的偏移 
		//printf("%d\n",p[i]);
	}
	return p;
} 

void test(){
	struct Teacher ** p=NULL;
	p=allocateSpace();
	if(p!=NULL){
		printf("%s\n","已经初始化");
	}
	
} 

int main(){
	test();
}
