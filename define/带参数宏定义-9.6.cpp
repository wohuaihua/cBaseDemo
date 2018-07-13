#define SQ(y) y*y
#include<stdio.h>

main(){
	int a,sq;
	printf("input a number :");
	scanf("%d",&a);
	//宏定义代换为:  a+1*a+1 
	sq=SQ(a+1);
	printf("sq=%d\n",sq);
} 
