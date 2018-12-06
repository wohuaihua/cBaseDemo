#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//按位取反
//00100100
//11011011 
void test(){
	//010 -> 取反 101(源码)  ->补码 
	int num=2;
	printf("int 占几个字节，%d\n",sizeof(int));
	printf("int 占多少位，%d\n",sizeof(int)*8);
	printf("~num=%d\n",~num);
}

//按位与 全真为真（全1为1） 
void test01(){
	int numOne=123;
	int numTwo=345;
	printf("%d\n",numOne&numTwo);
	
	//判断奇偶性 
	//01111011
	//00000001
	//数字&1   偶数为0，奇数为1 
	printf("可以判断奇偶性：123&1 \n") ;
	printf("可以判断奇偶性：%d,%d\n",123&1,124&1) ;
} 

//按位或 只要有一个真为真 
void test02(){
	int numOne=123;
	int numTwo=345;
	
	char bin[32];
	itoa(numOne|numTwo,bin,2);//2即是代表转换为2进制
    printf("%s\n",bin);
	printf("%d\n",numOne|numTwo);
	
	//将特定位变为1
	//01111011	123
	//00000100	4
	printf("将特定位变成1"); 
	memset(bin,0,32);
	itoa(123|4,bin,2);
	printf("%s\n",bin);
} 

//按位异或
//按位异或的性质
 
void test03(){
	int numOne=123;
	int numTwo=345;
	int result=290; 
	char bin[32];
	itoa(numOne^numTwo,bin,2);//2即是代表转换为2进制
    printf("%s\n",bin);
	printf("%d\n",numOne^numTwo);
	
	printf("numOne=123，numTwo=345，numOne^numTwo=290，按位异或的性质：\n");
	printf("290^123,结果为：%d\n",result^numOne); 
	printf("290^345,结果为：%d\n",result^numTwo); 
	
	printf("根据异或的性质，可交换数值:\n"); 
	printf("原先的数值：%d , %d\n",numOne,numTwo);
	
//	int temp;
//	temp=numOne;
//	numOne=numTwo;
//	numTwo=temp;
//	printf("借助中间变量交换数值: %d , %d\n",numOne,numTwo); 

//	numOne=numOne^numTwo;
//	numTwo=numOne^numTwo;
//	numOne=numOne^numTwo;
//	printf("借助异或交换数值: %d , %d\n",numOne,numTwo);

	//类似的，有运算，及反运算 -都可以实现数据的交换。 
	numOne=numOne+numTwo;
	numTwo=numOne-numTwo;
	numOne=numOne-numTwo;
	printf("借助减法交换数值: %d , %d\n",numOne,numTwo);
}

int main(){  
	test02();
} 
