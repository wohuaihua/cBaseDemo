#include<stdio.h>

void add(int *p);

main(){
	int a=10;
	int *p;
	p=&a;
	add(p);
	printf("%d",a);
}

//�޸� a ����ʵ�ڴ� 
void add(int *p){
	(*p)++;
}
