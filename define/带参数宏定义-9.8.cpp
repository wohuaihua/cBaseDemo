#include<stdio.h>
#define SQ(y) ((y)*(y))

main(){
	int a,sq;
	printf("input a number:");
	scanf("%d",&a);
	//�궨��չ��ʱ��Ҫע�� 
	sq=SQ(a+1);
	printf("%d\n",sq);
}
