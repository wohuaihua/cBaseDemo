#include<stdio.h>

main(){
	int *p1,*p2,*p,a,b;
	scanf("%d %d",&a,&b);
	//指针变量p1,p2,代表&a,&b的地址 
	p1=&a;p2=&b;
	//这边是地址互换 
	if(a<b){
		p=p1;
		p1=p2;
		p2=p;
	} 
	printf("\na=%d,b=%d\n",a,b);
	printf("max=%d,min=%d\n",*p1,*p2);
}
