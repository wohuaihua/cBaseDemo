#include<stdio.h>

void add(int *p);

main(){
	int a=10;
	int *p;
	p=&a;
	add(p);
	printf("%d",a);
}

//修改 a 的真实内存 
void add(int *p){
	(*p)++;
}
