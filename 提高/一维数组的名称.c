#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void printfArray(int * arr,/**int arr[],**/int length){  // int arr[] (可读性更强) 与 int * arr 其实是等价的  
	int i=0;
	for(i=0;i<length;i++){
		printf("%d\n",arr[i]);
		//printf("%d\n",*(arr+i));
	} 
}

void test(){
	int arr[5]={1,2,3,4,5};
	//本质并不是一个指针 
	printf("数组名称的长度，%d\n",sizeof(arr));
	int num=10;
	int * p=&num;
	//32位系统4个字节，64位系统8个字节
	printf("指针的长度，%d\n",sizeof(p));
	
	//除了两种特殊情况下，一维数组名称是指针元素的首地址
	//特殊情况1：对数组名称 sizeof 
	//特殊情况2：对数组名称取地址
	
	//这个没有报错，会有一个警告,估计和编译器有关 
	//int * a=&arr;
	int * b=arr;
	//printf("int * a=&arr , %d\n",a);
	printf("&arr , %d\n",&arr);
	printf("&arr+1 , %d\n",&arr+1);
	printf("int * b=arr , %d\n",b);
	
	//数组名称，指针常量，指针的指向是不可以修改的 
	//arr=NULL;
	
	//指针指向的值是可以修改的  int * const p 
	arr[0]=100;
	int arrLength=sizeof(arr)/sizeof(int);
	printfArray(arr,arrLength);
	
	//指针的偏移
	b=b+3;
	printf("指针的偏移: b=b+3; b[0]   %d\n",b[0]);
	//[] 内可以填写负数 
	printf("指针的偏移: b=b+3; b[-1]  %d\n",b[-1]);
	//b[-1] 这个 *(p-1) 是等价的 
	printf("指针的偏移: b=b+3; *(p-1) %d\n",*(b-1)) ;
} 


int main(){
	test();
} 
