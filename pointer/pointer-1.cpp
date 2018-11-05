#include<stdio.h>

/**
*	可以将函数放到main方法之后，但是前面必须加定义 void add(int a); 
*/
void add(int a){
	a++;
}

main(){
	int a=10;
	add(a);
	printf("%d",a);
}

