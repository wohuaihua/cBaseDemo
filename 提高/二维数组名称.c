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
	
	//二维数组名称指向第一个一维数组的指针 
	int (*p)[3]=arr;
	printf("%d\n",p); 
	printf("%d\n",p+1);
	
	//特殊情况
	//sizeof 统计的是数组的总字节数
	printf("%d\n",sizeof(arr)); 
	//对数组名取地址 二维数组指针变量
	int (*p2)[3][3]=&arr; 
	printf("%d\n",p2);
	printf("%d\n",arr[1][2]);
	printf("%d\n",*(*(arr+1)+2));//指针的偏移 
} 

void printArray(int (*p)[3],int rowNum,int columNum){// int (*p)[3] 与 int arr[3][3]是等价的 
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
//数组指针	是一个指向数组的指针  int(*p)[10]; 
//指针数组  是一个存放指针的数组  int *p[10];
int main(){
	test01();
}
