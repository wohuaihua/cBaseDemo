#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//��λȡ��
//00100100
//11011011 
void test(){
	//010
	int num=2;
	printf("int ռ�����ֽڣ�%d\n",sizeof(int));
	printf("int ռ����λ��%d\n",sizeof(int)*8);
	printf("~num=%d\n",~num);
}

int main(){
	test();
} 
