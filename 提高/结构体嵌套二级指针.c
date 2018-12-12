#include<stdio.h>
#include <string.h>
#include <stdlib.h>


#include <sys/timeb.h>
#if defined(WIN32)
# define  TIMEB    _timeb
# define  ftime    _ftime
typedef __int64 TIME_T;
#else
#define TIMEB timeb
typedef long long TIME_T;
#endif

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
		(*(p+i))->students=malloc(sizeof(char *)*4);
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
	struct TIMEB ts1,ts2;
    TIME_T t1,t2;
    int ti;
    ftime(&ts1);//开始计时
    t1=(TIME_T)ts1.time*1000+ts1.millitm;
	
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
		(*(*p+i))->students= malloc(sizeof(char *)*4);
		
		int j=0;
		for(j=0;j<4;j++){
			((*(*p+i))->students)[j]=malloc(sizeof(char)*64);
			sprintf(((*(*p+i))->students)[j],"teacher_%d_student_%d",i+1,j+1); 
		} 
	}
	
	ftime(&ts2);//停止计时
    t2=(TIME_T)ts2.time*1000+ts2.millitm;
    printf("allocateMem interval=%d\n",t2-t1);
} 

void printfTeacher(struct Teacher ** p,int sum){
	printf("\n");
	printf("开始读取数据\n");
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

//同级指针释放内存 
void freeSpace(struct Teacher ** p,int sum,int num){
	struct TIMEB ts1,ts2;
    TIME_T t1,t2;
    int ti;
    ftime(&ts1);//开始计时
    t1=(TIME_T)ts1.time*1000+ts1.millitm;
	
	int i=0;
	for(i=0;i<sum;i++){
		// 因为struct Teacher ** p 这是个二级指针 p 代表的是结构体指针数组 
		// 释放teacher * name 
		if((*(p+i))->name!=NULL){
			printf("释放 teacher * name -> %s\n",(*(p+i))->name);
			free((*(p+i))->name);
			(*(p+i))->name=NULL;
		}
		
		//释放 student 的每个名字 
		int j=0;
		for(j=0;j<num;j++){
			if(((*(p+i))->students)[j]!=NULL){
				free(((*(p+i))->students)[j]);
				((*(p+i))->students)[j]=NULL;
			} 
		}
		//释放	student 数组  
		if((*(p+i))->students!=NULL) {
			free((*(p+i))->students) ;
			(*(p+i))->students=NULL;
		}
		
		//释放每个老师
		if(*(p+i)!=NULL){
			free(*(p+i));
			*(p+i)=NULL;
		} 
	}
	if(p!=NULL){
		free(p);
		p=NULL;
	}
	
	ftime(&ts2);//停止计时
    t2=(TIME_T)ts2.time*1000+ts2.millitm;
    printf("freeSpace interval=%d\n",t2-t1);
} 

//高级指针释放内存 
void freeMem(struct Teacher *** p,int sum){
	printf("\n");
	printf("开始释放内存\n"); 
	int i=0;
	for(i=0;i<sum;i++){
		if((*(*p+i))->name!=NULL){
			free((*(*p+i))->name);
			(*(*p+i))->name=NULL;
		}
		
		int j=0;
		for(j=0;j<4;j++){
			if((*(*p+i))->students[j]!=NULL){
				free((*(*p+i))->students[j]);
				(*(*p+i))->students[j]=NULL;
			}
		}
		
		if((*(*p+i))->students!=NULL){
			free((*(*p+i))->students);
			(*(*p+i))->students=NULL;
		}
		
		if(*(*p+i)!=NULL){
			free(*(*p+i));
			*(*p+i)=NULL;
		}
	}
	if(*p!=NULL){
		free(*p);
		*p=NULL;
	}
} 

void test(){
	struct Teacher ** p;
	//同级指针开辟内存 
	//p=allocateSpace(3); 
	//printfTeacher(p,3);
	
	//高级指针开辟内存 
	allocateMem(&p,3);
	printfTeacher(p,3);
	
	//同级指针释放内存 
	//freeSpace(p,3,4);
	
	freeMem(&p,3);
	
	//查看是否释放干净 
	//printfTeacher(p,3);
	//防止野指针 
	p=NULL;
}

int main(){
	test();
}
