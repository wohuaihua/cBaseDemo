#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//按位取反
//00100100
//11011011 
void test(){
	//010
	int num=2;
	printf("int 占几个字节，%d\n",sizeof(int));
	printf("int 占多少位，%d\n",sizeof(int)*8);
	printf("~num=%d\n",~num);
}

int main(){
	test();
} 
