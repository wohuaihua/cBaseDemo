#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void printfArray(int * arr,/**int arr[],**/int length){  // int arr[] (�ɶ��Ը�ǿ) �� int * arr ��ʵ�ǵȼ۵�  
	int i=0;
	for(i=0;i<length;i++){
		printf("%d\n",arr[i]);
		//printf("%d\n",*(arr+i));
	} 
}

void test(){
	int arr[5]={1,2,3,4,5};
	//���ʲ�����һ��ָ�� 
	printf("�������Ƶĳ��ȣ�%d\n",sizeof(arr));
	int num=10;
	int * p=&num;
	//32λϵͳ4���ֽڣ�64λϵͳ8���ֽ�
	printf("ָ��ĳ��ȣ�%d\n",sizeof(p));
	
	//����������������£�һά����������ָ��Ԫ�ص��׵�ַ
	//�������1������������ sizeof 
	//�������2������������ȡ��ַ
	
	//���û�б�������һ������,���ƺͱ������й� 
	//int * a=&arr;
	int * b=arr;
	//printf("int * a=&arr , %d\n",a);
	printf("&arr , %d\n",&arr);
	printf("&arr+1 , %d\n",&arr+1);
	printf("int * b=arr , %d\n",b);
	
	//�������ƣ�ָ�볣����ָ���ָ���ǲ������޸ĵ� 
	//arr=NULL;
	
	//ָ��ָ���ֵ�ǿ����޸ĵ�  int * const p 
	arr[0]=100;
	int arrLength=sizeof(arr)/sizeof(int);
	printfArray(arr,arrLength);
	
	//ָ���ƫ��
	b=b+3;
	printf("ָ���ƫ��: b=b+3; b[0]   %d\n",b[0]);
	//[] �ڿ�����д���� 
	printf("ָ���ƫ��: b=b+3; b[-1]  %d\n",b[-1]);
	//b[-1] ��� *(p-1) �ǵȼ۵� 
	printf("ָ���ƫ��: b=b+3; *(p-1) %d\n",*(b-1)) ;
} 


int main(){
	test();
} 
