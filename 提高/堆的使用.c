#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
*	C99��־��ʼ��֧�� for(int i=0;i<5;i++) ���ַ�ʽforѭ�� 
*/
 
int * getSpace(){
	//pָ�����ռ���׵�ַ 
	int *p=malloc(sizeof(int)*5);
	if(p==NULL){
		return NULL;
	}
	
	int i;
	for(i=0;i<5;i++){
		p[i]=i+100;
	}
	return p; 
} 


void test(){
	int *p=getSpace();
	int i;
	for(i=0;i<5;i++){
		printf("%d\n",p[i]);
	}
	free(p);
	//��ֹҰָ�� 
	p=NULL; 
}

int main(){
	test();
	system("pause");
}
