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
		//������������ p��ŵ��ǵ�ַ�������������Ľṹ��  
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

//ͨ��ͬ��ָ������ڴ��ͷ� 
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

//ͨ���߼�ָ���ͷ��ڴ� 
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
	//�����ṹ������ 
	struct Person ** p;
	p=allocateSpace(3);
	printfPersonArr(p,3);
	//ͬ��ָ���ͷ� 
	freeSpace(p,3);
	p=NULL;
	
	//�߼�ָ���ͷ�
	//freeArr(&p,3); 
	if(p==NULL){
		printf("�Ѿ��ͷ�"); 
	}
}


int main(){
	test();
}
