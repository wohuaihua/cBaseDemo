#include<stdio.h>
#include <string.h>
#include <stdlib.h>


struct Person{
	char * name;
	int age;
};

struct Person **  allocateSpace(int size){
	struct Person ** p=malloc(sizeof(struct Person *)*size);
	int i=0;
	for(i=0;i<size;i++){
		//这个是有问题的 p存放的是地址，而不是真正的结构体  
		*(p+i)=malloc(sizeof(struct Person));
		//p[i]=malloc(sizeof(struct Person));
		(*(p+i))->name=malloc(sizeof(char)*64);
		sprintf((*(p+i))->name,"name_%d",i+1);
		 (*(p+i))->age=i+18;
	}
	return p;
}
void printfPersonArr(struct Person ** p,int sum){
	int i=0;
	for(i=0;i<sum;i++){
		printf("%s,%d\n",(*(p+i))->name,(*(p+i))->age);
	} 
}

//通过同级指针进行内存释放 
void freeSpace(struct Person ** p,int sum){
	int i=0;
	for(i=0;i<sum;i++){
		if((*(p+i))->name!=NULL){
			free((*(p+i))->name);
			(*(p+i))->name=NULL;
		}
		if(*(p+i)!=NULL){
			free(*(p+i));
			*(p+i)=NULL;
		}
	}
	if(p!=NULL){
		free(p);
		p=NULL;
	}
}

//通过高级指针释放内存 
void freeArr(struct Person *** p,int sum){
	int i=0;
	for(i=0;i<sum;i++){
	//	(*((*p)+i))->name;
	//	printf("%s\n",(*((*p)+i))->name);
		if((*((*p)+i))->name!=NULL){
			free((*((*p)+i))->name);
			(*((*p)+i))->name=NULL;
		}
		if(*((*p)+i)!=NULL){
			free(*((*p)+i));
			*((*p)+i)=NULL;
		}	
	}
	if(*p!=NULL){
		free(*p);
		*p=NULL;
	} 
}

test(){
	//创建结构体数组 
	struct Person ** p;
	p=allocateSpace(3);
	printfPersonArr(p,3);
	//同级指针释放 
	freeSpace(p,3);
	p=NULL;
	
	//高级指针释放
	//freeArr(&p,3); 
	if(p==NULL){
		printf("已经释放"); 
	}
}


int main(){
	test();
}
