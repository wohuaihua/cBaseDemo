#include<stdio.h>

void swap(int *p1,int *p2){
	//*p1λa�ĵ�ַ��*p2λb�ĵ�ַ 
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
	//pΪָ�������*p����a��ֵ 
	printf("%d\n",*p); 
	//&*p=&a,Ϊa�ĵ�ַ 
	printf("%d\n",&*p);
	//*&a=*p,����a��ֵ 
	printf("%d\n",*&a);
	//a�ĵ�ַ 
	printf("%d\n",&a);
	//a�ĵ�ַ 
	printf("%d\n",(p)++);
	//a����һ���ڴ浥Ԫ�ĵ�ַ 
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
