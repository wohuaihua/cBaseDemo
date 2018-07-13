#include<stdio.h>
#define SQ(y) ((y)*(y))

main(){
	int a,sq;
	printf("input a number:");
	scanf("%d",&a);
	//宏定义展开时，要注意 
	sq=SQ(a+1);
	printf("%d\n",sq);
}
