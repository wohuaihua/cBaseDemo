#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct Teacher{
	char * name;
	char ** students;
};

//ͬ��ָ����з����ڴ�  
struct Teacher ** allocateSpace(int sum){
	struct Teacher ** p=malloc(sizeof(struct Teacher *)*3);
	int i=0;
	for(i=0;i<sum;i++){
		
		//���СΪ16 ,Ϊ2��ָ��(* name,** students)��С��� 
		printf("����malloc(sizeof(struct Teacher))���ڴ�Ϊ %d\n",sizeof(struct Teacher)) ;
		//Ϊ3����ʦ�����ڴ�
		*(p+i)=malloc(sizeof(struct Teacher));
		//Ϊ * name ָ�뿪���ڴ� 
		(*(p+i))->name=malloc(sizeof(char)*64);
		sprintf((*(p+i))->name,"teacher_%d",i+1);
		
		//Ϊ ** students �����ڴ� 
		(*(p+i))->students=malloc(sizeof(char)*4);
		int j=0;
		//Ϊÿ��ѧ�������ڴ� 
		for(j=0;j<4;j++){
			((*(p+i))->students)[j]=malloc(sizeof(char)*64);
			sprintf(((*(p+i))->students)[j],"teacher_%d_student_%d",i+1,j+1);
		}
	}
	return p; 
} 

//�߼�ָ�뿪�ٿռ� 
void allocateMem(struct Teacher ***p,int sum){
	//���� **p���ڴ�
	*p=malloc(sizeof(struct Teacher *)*3);
	//Ϊ3����ʦ�����ڴ�
	int i=0;
	for(i=0;i<sum;i++){
		//Ϊ��ʦ�����ڴ� 
		*(*p+i)=malloc(sizeof(struct Teacher *)*3); 
		//Ϊ * name ָ�뿪���ڴ�
		(*(*p+i))->name=malloc(sizeof(char)*64);
		sprintf((*(*p+i))->name,"teacher_%d",i+1) ;
		
		//Ϊ ** students �����ڴ�
		(*(*p+i))->students= malloc(sizeof(char)*4);
		
		int j=0;
		for(j=0;j<4;j++){
			*((*(*p+i))->students+j)=malloc(sizeof(char)*64);
			sprintf(*((*(*p+i))->students+j),"teacher_%d_student_%d",i+1,j+1); 
		} 
	}
} 

void printfTeacher(struct Teacher ** p,int sum){
	int i=0;
	for(i=0;i<sum;i++){
		printf("��ʦ����Ϊ :%s\n",(*(p+i))->name);
		int j=0;
		for(j=0;j<sum;j++){
			//���������ַ�ʽ������ 
			//printf("ѧ������Ϊ��%s\n",*(((*(p+i))->students)+j));
			printf("ѧ������Ϊ��%s\n",((*(p+i))->students)[j]);
		}
	}
} 

//ͬ��ָ���ͷ��ڴ� 
void freeSpace(struct Teacher ** p,int sum,int num){
	int i=0;
	for(i=0;i<sum;i++){
		//�ͷ� * name 
		if((*(p+i))->name!=NULL){
			free((*(p+i))->name);
			(*(p+i))->name=NULL;
		}
		
		int j=0;
		for(j=0;j<num;j++){
			//�ͷ� students ÿһ��������ڴ�ռ�  
			if(*((*(p+i))->students+j)!=NULL){
				free(*((*(p+i))->students+j));
				*((*(p+i))->students+j)=NULL;
			}
		}
		//�ͷ�  * students
		if((*(p+i))->students!=NULL){
			free((*(p+i))->students);
			(*(p+i))->students=NULL;
		}
		//�ͷ� ÿһ������� 
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

void test(){
	struct Teacher ** p;
	//ͬ��ָ�뿪���ڴ� 
	//p=allocateSpace(3); 
	//printfTeacher(p,3);
	
	//�߼�ָ�뿪���ڴ� 
	allocateMem(&p,3);
	//printfTeacher(p,3);
	
	freeSpace(p,3,4);
}

int main(){
	test();
}
