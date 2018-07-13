#include"stdio.h"

//p1,p2代表指针变量。*p1,*p2代表指针变量指定具体的值 
void swap(int *p1,int *p2){
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
} 

main(){
	int a,b;
	int *pointer_1,*pointer_2;
	scanf("%d,%d",&a,&b);
	pointer_1=&a;
	pointer_2=&b;
	printf("%d %d\n",pointer_1,pointer_2);
	if(a<b){
		swap(pointer_1,pointer_2);
		printf("\n%d,%d\n",a,b);
	} 
} 
