#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//��λȡ��
//00100100
//11011011 
void test(){
	//010 -> ȡ�� 101(Դ��)  ->���� 
	int num=2;
	printf("int ռ�����ֽڣ�%d\n",sizeof(int));
	printf("int ռ����λ��%d\n",sizeof(int)*8);
	printf("~num=%d\n",~num);
}

//��λ�� ȫ��Ϊ�棨ȫ1Ϊ1�� 
void test01(){
	int numOne=123;
	int numTwo=345;
	printf("%d\n",numOne&numTwo);
	
	//�ж���ż�� 
	//01111011
	//00000001
	//����&1   ż��Ϊ0������Ϊ1 
	printf("�����ж���ż�ԣ�123&1 \n") ;
	printf("�����ж���ż�ԣ�%d,%d\n",123&1,124&1) ;
} 

//��λ�� ֻҪ��һ����Ϊ�� 
void test02(){
	int numOne=123;
	int numTwo=345;
	
	char bin[32];
	itoa(numOne|numTwo,bin,2);//2���Ǵ���ת��Ϊ2����
    printf("%s\n",bin);
	printf("%d\n",numOne|numTwo);
	
	//���ض�λ��Ϊ1
	//01111011	123
	//00000100	4
	printf("���ض�λ���1"); 
	memset(bin,0,32);
	itoa(123|4,bin,2);
	printf("%s\n",bin);
} 

//��λ���
//��λ��������
 
void test03(){
	int numOne=123;
	int numTwo=345;
	int result=290; 
	char bin[32];
	itoa(numOne^numTwo,bin,2);//2���Ǵ���ת��Ϊ2����
    printf("%s\n",bin);
	printf("%d\n",numOne^numTwo);
	
	printf("numOne=123��numTwo=345��numOne^numTwo=290����λ�������ʣ�\n");
	printf("290^123,���Ϊ��%d\n",result^numOne); 
	printf("290^345,���Ϊ��%d\n",result^numTwo); 
	
	printf("�����������ʣ��ɽ�����ֵ:\n"); 
	printf("ԭ�ȵ���ֵ��%d , %d\n",numOne,numTwo);
	
//	int temp;
//	temp=numOne;
//	numOne=numTwo;
//	numTwo=temp;
//	printf("�����м����������ֵ: %d , %d\n",numOne,numTwo); 

//	numOne=numOne^numTwo;
//	numTwo=numOne^numTwo;
//	numOne=numOne^numTwo;
//	printf("������򽻻���ֵ: %d , %d\n",numOne,numTwo);

	//���Ƶģ������㣬�������� -������ʵ�����ݵĽ����� 
	numOne=numOne+numTwo;
	numTwo=numOne-numTwo;
	numOne=numOne-numTwo;
	printf("��������������ֵ: %d , %d\n",numOne,numTwo);
}

int main(){  
	test02();
} 
