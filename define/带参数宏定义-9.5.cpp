#include<stdio.h>
#define SQ(y) (y)*(y)

//在宏定义中的形参是标识符，而调用中的实参可以是表达式 
main(){
	int a,sq;
	printf("input number:	");
	scanf("%d",&a);
	sq=SQ(a+1);
	printf("sq=%d\n",sq); 
}                   
