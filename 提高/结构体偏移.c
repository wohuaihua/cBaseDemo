#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h> 

struct Person{
	char a; //0~3 
	int b;  //4~8
};

//�ṹ���b��ƫ���� 
void test(){
	printf("b��ƫ����Ϊ�� %d\n",offsetof(struct Person,b));
}

void test01(){
	struct Person person;
	struct Person * p=&person;
	
	printf("b��ƫ������%d\n",(int)(&(p->b))-(int)p);
	//pָ��ĵ�ַ ��(int)p ����ͬ�� 
	printf("ָ��ĵ�ַ��%d ��(int)p�ĵ�ַ��%d",p,(int)p);
} 

void test02(){
	struct Person p={'a',10};
	
	printf("p.b = %d\n",*(int *)((char *)&p+offsetof(struct Person,b)));
	//ָ���ƫ�� 
	printf("p.b = %d\n",*((int *)&p+1)); 
}

struct Child{
	char a;
	int b;
	struct Person c;
}; 

//ͨ��ƫ������ȡֵ 
void test03(){
	struct Child child={'a',10,'b',20};
	int offset1=offsetof(struct Child,c);
	int offset2=offsetof(struct Person,b);
	//(char *)&child+offset1+offsetof2
	printf("%d\n",*(int *)((char *)&child+offset1+offset2));
	
	printf("%d\n", ((struct Person *)((char *)&child + offset1))->b); 
}

int main(){
	test02();
}
