#include<stdio.h>
#include <string.h>
#include <stdlib.h>


struct Teacher{
	char * name;
	char ** students;
};

void printfTeacher(struct Teacher ** p,int sum){
	printf("\n");
	printf("%s\n","��ʼ��ȡ����");
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

struct Teacher ** allocateSpace(){
	printf("%s\n","��ʼ�����ڴ�");
	struct Teacher ** p=malloc(sizeof(struct Teacher *)*3);
	int i;
	for(i=0;i<3;i++){
		//ָ��� p+i ��  p[i] �ǲ�һ����  ��p[i]���� *(p+i) ,p+i����ָ���ƫ�� 
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
	printf("%s\n","��ʼ�ͷ��ڴ�"); 
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
		printf("%s\n","�Ѿ���ʼ��");
	}
	printfTeacher(p,3); 
	freeSpace(p,3);
	//��ֹҰָ�� 
	//��ӡ������鿴�ڴ��Ƿ��ͷŸɾ� 
	//printfTeacher(p,3); 
	p=NULL;
} 

int main(){
	test();
}
