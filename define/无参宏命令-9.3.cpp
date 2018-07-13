#include<stdio.h>
#define P printf
#define D "%d\n"
#define F "%f\n"

main(){
	int a=5,c=8,e=11;
	float b=3.8,d=9.7,f=21.08;
	//D F 之间没有逗号 
	P(D F,a,b);
	P(D F,c,d);
	P(D F,e,f);
}
