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
		//ָ��� p+i ��  p[i] �ǲ�һ����  ��p[i]���� *(p+i) ,p+i����ָ���ƫ�� 
		//printf("%d\n",p[i]);
	}
	return p;
} 

void test(){
	struct Teacher ** p=NULL;
	p=allocateSpace();
	if(p!=NULL){
		printf("%s\n","�Ѿ���ʼ��");
	}
	
} 

int main(){
	test();
}
