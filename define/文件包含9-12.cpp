#include"stdio.h"
#include"stdlib.h"
//#include<stdio.h>
//#include"stdio.h"
//这2种是有区别的：使用尖括号表示在包含文件目录去查找（包含目录是用户在设置环境时设置的） 
//而不再源文件目录去查找

//双引号则标识首先在当前的源文件目录中查找，未找到才到包含的目录中去查找。

#define NUM ok
main(){ 
	struct stu{
		int num;
		char *name;
		char sex;
		
		float score;
	} *ps;
	//向系统申请指定大小的内存空间 
	ps=(struct stu*)malloc(sizeof(struct stu));
	ps->num=102;
	ps->name="Zhang ping";
	ps->sex='M';
	ps->score=62.5;
	//如果NUM已经#define定义过，则对下面的程序编译 
	#ifdef NUM	//if define
	printf("Number=%d\nScore=%f\n",ps->num,ps->score);
	#else
	printf("Name=%s\nSex=%c\n",ps->name,ps->sex);
	#endif		//end if
	free(ps);
} 

//第二种形式
/*
#ifndef 标识符 	  //if not define 
	程序段1 
#else
	程序段2
#endif            //end if
*/ 

/**
第三种 形式
#if  常量表达式
	程序段1
#else
	程序段2
#endif 
*/

