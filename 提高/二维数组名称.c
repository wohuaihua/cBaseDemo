#include<stdio.h>
#include <string.h>
#include <stdlib.h>


void test(){
	int arr[3][3]={
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	
	int arr1[3][3]={1,2,3,4,5,6,7,8,9};
	
	int arr2[][3]={1,2,3,4,5,6,7,8,9};
	
	//��ά��������ָ���һ��һά�����ָ�� 
	int (*p)[3]=arr;
	printf("%d\n",p); 
	printf("%d\n",p+1);
	
	//�������
	//sizeof ͳ�Ƶ�����������ֽ���
	printf("%d\n",sizeof(arr)); 
	//��������ȡ��ַ ��ά����ָ�����
	int (*p2)[3][3]=&arr; 
	printf("%d\n",p2);
	printf("%d\n",arr[1][2]);
	printf("%d\n",*(*(arr+1)+2));//ָ���ƫ�� 
} 

void printArray(int (*p)[3],int rowNum,int columNum){// int (*p)[3] �� int arr[3][3]�ǵȼ۵� 
	int i=0;
	for(i=0;i<rowNum;i++){
		int j=0;
		for(j=0;j<columNum;j++){
			//printf("%d\t",p[i][j]);
			printf("%d\t",*(*(p+i)+j));
		}
		printf("\n");
	}
} 

void test01(){
	int arr[3][3]={
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int (*p)[3]=arr;
	printArray(p,3,3);
} 
//����ָ��	��һ��ָ�������ָ��  int(*p)[10]; 
//ָ������  ��һ�����ָ�������  int *p[10];
int main(){
	test01();
}
