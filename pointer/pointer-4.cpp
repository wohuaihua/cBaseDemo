#include<stdio.h>

/**
*	����ָ�� 
*/

void move_p(int **p,int arr[]){
	*p=&arr[1];
}

main(){
	int arr[]={5,6,7,8,9};
	//ָ�������׵�ַ 
	int *p=&arr[0];
	//����������ָ��ĵ�ַ 
	move_p(&p,arr);
	printf("%d",*p);
}

