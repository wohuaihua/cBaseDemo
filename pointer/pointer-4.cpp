#include<stdio.h>

/**
*	二级指针 
*/

void move_p(int **p,int arr[]){
	*p=&arr[1];
}

main(){
	int arr[]={5,6,7,8,9};
	//指向数组首地址 
	int *p=&arr[0];
	//参数传的是指针的地址 
	move_p(&p,arr);
	printf("%d",*p);
}

