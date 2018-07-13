#include<stdio.h>
#define SQ(y) (y)*(y)

main(){
	int a,sq;
	printf("input a number: ");
	scanf("%d",&a);
	//ºê´ú»»Îª£º sq=160/(a+1)*(a+1) 
	sq=160/SQ(a+1);
	printf("sq=%d\n",sq);
}
