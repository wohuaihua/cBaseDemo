#include<stdio.h>
#include <string.h>
#include <stdlib.h>


struct Person {
	char name[30];
	int age;
	char address[50];
	double weight;
};

//���ַ�ʽ���β��Ǹ���ʵ�Σ�����ջ�У�ջ�洢�ռ����Ľϴ�  
void printPerson(struct Person p){
	printf("1 \t������%s\t ���䣬%d\t ��ַ,%s\t ���أ�%f\t\n",p.name,p.age,p.address,p.weight);
	p.age=16;
}

//���ַ�ʽ����ָ���ַ��ջ�еĿռ����ıȽ�С 
//����ָ�룬���ֱ���޸���ֵ 
// const ��ֹ����� 
void printPersonPointer(const struct Person * p){
	printf("2 \t������%s\t ���䣬%d\t ��ַ,%s\t ���أ�%f\t\n",p->name,p->age,p->address,p->weight);
	//const ���Σ�����ֱ���޸ģ����Լ���޸ġ� 
	//p->age=16;
	
	//����޸� 
	int * age_pointer=(int *)&(p->age); 
	*age_pointer=16;
	printf("%d\n",age_pointer);
} 

void test(){
	struct Person p={"hah",18,"����פ���",100};
	printPerson(p);
	printf("1 \t������%s\t ���䣬%d\t ��ַ,%s\t ���أ�%f\t\n",p.name,p.age,p.address,p.weight);
	printPersonPointer(&p); 
	struct Person *pp=&p;
	printf("2 \t������%s\t ���䣬%d\t ��ַ,%s\t ���أ�%f\t\n",pp->name,pp->age,pp->address,pp->weight);
}



int main(){
	test();
}
