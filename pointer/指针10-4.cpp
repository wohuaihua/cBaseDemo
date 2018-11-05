#include<stdio.h>

void swap(int *p1,int *p2){
	//*p1位a的地址，*p2位b的地址 
	int *p;
	p=p1;
	p1=p2;
	p2=p;
} 

main(){
	/*
	int a,*p;
	scanf("%d",&a);
	p=&a;
	//p为指针变量，*p代表a的值 
	printf("%d\n",*p); 
	//&*p=&a,为a的地址 
	printf("%d\n",&*p);
	//*&a=*p,代表a的值 
	printf("%d\n",*&a);
	//a的地址 
	printf("%d\n",&a);
	//a的地址 
	printf("%d\n",(p)++);
	//a的下一个内存单元的地址 
	printf("%d\n",p++);
	*/
	int a,b;
	int *pointer_1,*pointer_2;
	scanf("%d,%d",&a,&b);
	pointer_1=&a;
	pointer_2=&b;
	printf("\n%d,%d\n",pointer_1,pointer_2); 
	if(a<b) 
		swap(pointer_1,pointer_2);
		printf("%d,%d",a,b);
	//printf("\n%d,%d\n",pointer_1,pointer_2); 
	//printf("\n%d,%d\n",*pointer_1,*pointer_2); 
}
