#include<stdio.h>

/**
*	���Խ������ŵ�main����֮�󣬵���ǰ�����Ӷ��� void add(int a); 
*/
void add(int a){
	a++;
}

main(){
	int a=10;
	add(a);
	printf("%d",a);
}

