#include"stdio.h"
#include"stdlib.h"
//#include<stdio.h>
//#include"stdio.h"
//��2����������ģ�ʹ�ü����ű�ʾ�ڰ����ļ�Ŀ¼ȥ���ң�����Ŀ¼���û������û���ʱ���õģ� 
//������Դ�ļ�Ŀ¼ȥ����

//˫�������ʶ�����ڵ�ǰ��Դ�ļ�Ŀ¼�в��ң�δ�ҵ��ŵ�������Ŀ¼��ȥ���ҡ�

#define NUM ok
main(){ 
	struct stu{
		int num;
		char *name;
		char sex;
		
		float score;
	} *ps;
	//��ϵͳ����ָ����С���ڴ�ռ� 
	ps=(struct stu*)malloc(sizeof(struct stu));
	ps->num=102;
	ps->name="Zhang ping";
	ps->sex='M';
	ps->score=62.5;
	//���NUM�Ѿ�#define��������������ĳ������ 
	#ifdef NUM	//if define
	printf("Number=%d\nScore=%f\n",ps->num,ps->score);
	#else
	printf("Name=%s\nSex=%c\n",ps->name,ps->sex);
	#endif		//end if
	free(ps);
} 

//�ڶ�����ʽ
/*
#ifndef ��ʶ�� 	  //if not define 
	�����1 
#else
	�����2
#endif            //end if
*/ 

/**
������ ��ʽ
#if  �������ʽ
	�����1
#else
	�����2
#endif 
*/

