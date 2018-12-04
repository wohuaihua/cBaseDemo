#include<stdio.h>
#include <string.h>
#include <stdlib.h>


struct Person {
	char name[30];
	int age;
	char address[50];
	double weight;
};

//这种方式，形参是复制实参，放入栈中，栈存储空间消耗较大  
void printPerson(struct Person p){
	printf("1 \t姓名，%s\t 年龄，%d\t 地址,%s\t 体重，%f\t\n",p.name,p.age,p.address,p.weight);
	p.age=16;
}

//这种方式，传指针地址，栈中的空间消耗比较小 
//传入指针，则可直接修改其值 
// const 防止误操作 
void printPersonPointer(const struct Person * p){
	printf("2 \t姓名，%s\t 年龄，%d\t 地址,%s\t 体重，%f\t\n",p->name,p->age,p->address,p->weight);
	//const 修饰，不能直接修改，可以间接修改。 
	//p->age=16;
	
	//间接修改 
	int * age_pointer=(int *)&(p->age); 
	*age_pointer=16;
	printf("%d\n",age_pointer);
} 

void test(){
	struct Person p={"hah",18,"河南驻马店",100};
	printPerson(p);
	printf("1 \t姓名，%s\t 年龄，%d\t 地址,%s\t 体重，%f\t\n",p.name,p.age,p.address,p.weight);
	printPersonPointer(&p); 
	struct Person *pp=&p;
	printf("2 \t姓名，%s\t 年龄，%d\t 地址,%s\t 体重，%f\t\n",pp->name,pp->age,pp->address,pp->weight);
}



int main(){
	test();
}
