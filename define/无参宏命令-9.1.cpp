#define M (y*y+3*y)
#include<stdio.h>  

main(){ 
	int s,y;
	printf("input a number:    ");
	scanf("%d",&y);
	s=3*M+4*M+5*M;
	printf("s=%d\n",s);
}
