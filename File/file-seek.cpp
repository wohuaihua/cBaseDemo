#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct stu{
	char name[10];
	int num;
	int age;
	char addr[15];
} boy,*qq;


main(){
	FILE *fp;
	char ch;
	int i=1;
	qq=&boy;
	if((fp=fopen("C:\\Users\\hzh\\Desktop\\stu","rb"))==NULL){
		printf("Cannot open file strike any key exit!");
		getch();
		exit(1);
	}
	rewind(fp);
	/**
	* ��һ���������ļ�ָ��
	* �ڶ����������ֽ�ƫ����
	* ������������ʼλ�� 0���ļ��ף�1����ǰλ�ã�2�ļ�β 
	*/
	fseek(fp,i*sizeof(struct stu),0);
	/**
	*	�ļ�������⺯�� 
	*/
	printf("%d\n",feof(fp));
	/**
	*	��д�ļ������⺯�� 
	*/
	printf("%d\n",ferror(fp)); 
	fread(qq,sizeof(struct stu),1,fp);
	printf("%s%d%d%s\n",qq->name,qq->num,qq->age,qq->addr);	
	printf("%d\n",feof(fp));
	printf("%d\n",ferror(fp)); 
	fclose(fp); 
	printf("%d\n",feof(fp));
	printf("%d\n",ferror(fp)); 
}
