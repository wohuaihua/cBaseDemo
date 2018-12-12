#include<stdio.h>
#include <string.h>
#include <stdlib.h>


struct Teacher{
	char * name;
	char ** students;
};

void printfTeacher(struct Teacher ** p,int sum){
	printf("\n");
	printf("%s\n","开始读取数据");
	int i=0;
	for(i=0;i<sum;i++){
		printf("老师名称为 :%s\n",(*(p+i))->name);
		int j=0;
		for(j=0;j<4;j++){
			//以下这两种方式都可以 
			//printf("学生名称为：%s\n",*(((*(p+i))->students)+j));
			printf("\t学生名称为：%s\n",((*(p+i))->students)[j]);
		}
	}
} 

struct Teacher ** allocateSpace(){
	printf("%s\n","开始分配内存");
	struct Teacher ** p=malloc(sizeof(struct Teacher *)*3);
	int i;
	for(i=0;i<3;i++){
		//指针的 p+i 与  p[i] 是不一样的  ，p[i]代表 *(p+i) ,p+i代表指针的偏移 
		//printf("%d\n",p[i]);
		p[i]=malloc(sizeof(struct Teacher));
		p[i]->name=malloc(sizeof(char)*64); 
		sprintf(p[i]->name,"teacher_%d",i+1);
		p[i]->students=malloc(sizeof(char *)*4);
		int j=0;
		for(j=0;j<4;j++){
			(p[i]->students)[j]=malloc(sizeof(char)*64);
			printf("%d\n",(p[i]->students)[j]);
			sprintf((p[i]->students)[j],"teacher_%d_student_%d",i+1,j+1);
		}
	}
	return p;
} 

void freeSpace(struct Teacher ** p,int sum){
	printf("\n");
	printf("%s\n","开始释放内存"); 
	int i=0;
	for(i=0;i<sum;i++){
		if(p[i]->name!=NULL){
			free(p[i]->name);
			p[i]->name=NULL;
		} 
		
		int j=0;
		for(j=0;j<4;j++){
			if(p[i]->students[j]!=NULL){
				free(p[i]->students[j]);
				p[i]->students[j]=NULL;
			} 
		} 
		if(p[i]->students!=NULL){
			free(p[i]->students);
			p[i]->students=NULL;
		}
		if(p[i]!=NULL){
			free(p[i]);
			p[i]=NULL;
		}
	}
	if(p!=NULL){
		free(p);
		p=NULL;
	}
}

void test(){
	struct Teacher ** p=NULL;
	p=allocateSpace();
	if(p!=NULL){
		printf("%s\n","已经初始化");
	}
	printfTeacher(p,3); 
	freeSpace(p,3);
	//防止野指针 
	//打印输出，查看内存是否释放干净 
	//printfTeacher(p,3); 
	p=NULL;
} 

int main(){
	test();
}
