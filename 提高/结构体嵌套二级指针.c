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
		(*(p+i))->students=malloc(sizeof(char *)*4);
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
	struct TIMEB ts1,ts2;
    TIME_T t1,t2;
    int ti;
    ftime(&ts1);//��ʼ��ʱ
    t1=(TIME_T)ts1.time*1000+ts1.millitm;
	
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
		(*(*p+i))->students= malloc(sizeof(char *)*4);
		
		int j=0;
		for(j=0;j<4;j++){
			((*(*p+i))->students)[j]=malloc(sizeof(char)*64);
			sprintf(((*(*p+i))->students)[j],"teacher_%d_student_%d",i+1,j+1); 
		} 
	}
	
	ftime(&ts2);//ֹͣ��ʱ
    t2=(TIME_T)ts2.time*1000+ts2.millitm;
    printf("allocateMem interval=%d\n",t2-t1);
} 

void printfTeacher(struct Teacher ** p,int sum){
	printf("\n");
	printf("��ʼ��ȡ����\n");
	int i=0;
	for(i=0;i<sum;i++){
		printf("��ʦ����Ϊ :%s\n",(*(p+i))->name);
		int j=0;
		for(j=0;j<4;j++){
			//���������ַ�ʽ������ 
			//printf("ѧ������Ϊ��%s\n",*(((*(p+i))->students)+j));
			printf("\tѧ������Ϊ��%s\n",((*(p+i))->students)[j]);
		}
	}
} 

//ͬ��ָ���ͷ��ڴ� 
void freeSpace(struct Teacher ** p,int sum,int num){
	struct TIMEB ts1,ts2;
    TIME_T t1,t2;
    int ti;
    ftime(&ts1);//��ʼ��ʱ
    t1=(TIME_T)ts1.time*1000+ts1.millitm;
	
	int i=0;
	for(i=0;i<sum;i++){
		// ��Ϊstruct Teacher ** p ���Ǹ�����ָ�� p ������ǽṹ��ָ������ 
		// �ͷ�teacher * name 
		if((*(p+i))->name!=NULL){
			printf("�ͷ� teacher * name -> %s\n",(*(p+i))->name);
			free((*(p+i))->name);
			(*(p+i))->name=NULL;
		}
		
		//�ͷ� student ��ÿ������ 
		int j=0;
		for(j=0;j<num;j++){
			if(((*(p+i))->students)[j]!=NULL){
				free(((*(p+i))->students)[j]);
				((*(p+i))->students)[j]=NULL;
			} 
		}
		//�ͷ�	student ����  
		if((*(p+i))->students!=NULL) {
			free((*(p+i))->students) ;
			(*(p+i))->students=NULL;
		}
		
		//�ͷ�ÿ����ʦ
		if(*(p+i)!=NULL){
			free(*(p+i));
			*(p+i)=NULL;
		} 
	}
	if(p!=NULL){
		free(p);
		p=NULL;
	}
	
	ftime(&ts2);//ֹͣ��ʱ
    t2=(TIME_T)ts2.time*1000+ts2.millitm;
    printf("freeSpace interval=%d\n",t2-t1);
} 

//�߼�ָ���ͷ��ڴ� 
void freeMem(struct Teacher *** p,int sum){
	printf("\n");
	printf("��ʼ�ͷ��ڴ�\n"); 
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
	//ͬ��ָ�뿪���ڴ� 
	//p=allocateSpace(3); 
	//printfTeacher(p,3);
	
	//�߼�ָ�뿪���ڴ� 
	allocateMem(&p,3);
	printfTeacher(p,3);
	
	//ͬ��ָ���ͷ��ڴ� 
	//freeSpace(p,3,4);
	
	freeMem(&p,3);
	
	//�鿴�Ƿ��ͷŸɾ� 
	//printfTeacher(p,3);
	//��ֹҰָ�� 
	p=NULL;
}

int main(){
	test();
}
