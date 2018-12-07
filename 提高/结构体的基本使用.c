#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//结构体定义的时候，没有分配内存空间 
//struct Person{
//	char name[50];
//	int age;
//};

typedef struct Person{
	char name[50];
	int age;
} myPerson;

void printfPerson(struct Person p){
	printf("%s\n",p.name);
	printf("%d\n",p.age);
}

void test(){
	myPerson p={"123",23};
	printfPerson(p);
}


struct Person1{
	char name[50];
	int age;
} myPerson1 /**={"hzh",12}*/;

void test01(){
	myPerson1.age=123;
	strcpy(myPerson1.name,"hzh");
	printf("%s\n",myPerson1.name);
	printf("%d\n",myPerson1.age);
}

//匿名结构体 
struct {
	char name[50];
	int age;
} myPerson2;

void test02(){
	myPerson2.age=123;
	strcpy(myPerson2.name,"hzh");
	printf("%s\n",myPerson2.name);
	printf("%d\n",myPerson2.age);
}

void printfPersonArr(struct Person * p,int length){
	int i=0;
	for(i=0;i<length;i++){
		printf("%s , %d\n",(p+i)->name,(p+i)->age);
	} 
} 

void test03(){
	//在栈上创建结构体
	struct Person p={"name",12}; 
//	printfPerson(p);
	
	//在堆上创建结构体
	struct Person * pp=malloc(sizeof(struct Person)) ;
	pp->age=12;
	strcpy(pp->name,"hzh");
//	printfPerson(*pp);
	
	//在栈上创建结构体指针
	 struct Person pArr[]={
	 	{"1",1},
	 	{"2",2},
	 	{"3",3},
	 }; 
	 int length=sizeof(pArr)/sizeof(struct Person);
//	 printfPersonArr(pArr,length);
	 
	//在堆上创建结构体指针
	struct Person * pArrs=malloc(sizeof(struct Person)*6); 
	int i=0;
	for(i<0;i<6;i++){
		//(pArrs+i)->age=i;
		//strcpy((pArrs+i)->name,"asdsa");
		
		sprintf(pArrs[i].name,"name_%d",i);
		pArrs[i].age=i+18;
	}
	for(i =0;i<6;i++){
		printf("%s , %d\n",(pArrs+i)->name,(pArrs+i)->age) ;
	}
	if(pArrs!=NULL){
		free(pArrs);
		pArrs=NULL;
	}
} 

int main(){
	test03();
}
