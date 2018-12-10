#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct Teacher{
	char * name;
	char ** students;
};

//同级指针进行分配内存  
struct Teacher ** allocateSpace(int sum){
	struct Teacher ** p=malloc(sizeof(struct Teacher *)*3);
	int i=0;
	for(i=0;i<sum;i++){
		
		//其大小为16 ,为2个指针(* name,** students)大小相加 
		printf("分配malloc(sizeof(struct Teacher))的内存为 %d\n",sizeof(struct Teacher)) ;
		//为3个老师分配内存
		*(p+i)=malloc(sizeof(struct Teacher));
		//为 * name 指针开辟内存 
		(*(p+i))->name=malloc(sizeof(char)*64);
		sprintf((*(p+i))->name,"teacher_%d",i+1);
		
		//为 ** students 开辟内存 
		(*(p+i))->students=malloc(sizeof(char)*4);
		int j=0;
		//为每个学生开辟内存 
		for(j=0;j<4;j++){
			((*(p+i))->students)[j]=malloc(sizeof(char)*64);
			sprintf(((*(p+i))->students)[j],"teacher_%d_student_%d",i+1,j+1);
		}
	}
	return p; 
} 

//高级指针开辟空间 
void allocateMem(struct Teacher ***p,int sum){
	//开辟 **p的内存
	*p=malloc(sizeof(struct Teacher *)*3);
	//为3个老师分配内存
	int i=0;
	for(i=0;i<sum;i++){
		//为老师分配内存 
		*(*p+i)=malloc(sizeof(struct Teacher *)*3); 
		//为 * name 指针开辟内存
		(*(*p+i))->name=malloc(sizeof(char)*64);
		sprintf((*(*p+i))->name,"teacher_%d",i+1) ;
		
		//为 ** students 开辟内存
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
		printf("老师名称为 :%s\n",(*(p+i))->name);
		int j=0;
		for(j=0;j<sum;j++){
			//以下这两种方式都可以 
			//printf("学生名称为：%s\n",*(((*(p+i))->students)+j));
			printf("学生名称为：%s\n",((*(p+i))->students)[j]);
		}
	}
} 

//同级指针释放内存 
void freeSpace(struct Teacher ** p,int sum,int num){
	int i=0;
	for(i=0;i<sum;i++){
		//释放 * name 
		if((*(p+i))->name!=NULL){
			free((*(p+i))->name);
			(*(p+i))->name=NULL;
		}
		
		int j=0;
		for(j=0;j<num;j++){
			//释放 students 每一个分配的内存空间  
			if(*((*(p+i))->students+j)!=NULL){
				free(*((*(p+i))->students+j));
				*((*(p+i))->students+j)=NULL;
			}
		}
		//释放  * students
		if((*(p+i))->students!=NULL){
			free((*(p+i))->students);
			(*(p+i))->students=NULL;
		}
		//释放 每一个分配的 
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
	//同级指针开辟内存 
	//p=allocateSpace(3); 
	//printfTeacher(p,3);
	
	//高级指针开辟内存 
	allocateMem(&p,3);
	//printfTeacher(p,3);
	
	freeSpace(p,3,4);
}

int main(){
	test();
}
