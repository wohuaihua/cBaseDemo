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
	* 第一个参数是文件指针
	* 第二个参数是字节偏移量
	* 第三个代表起始位置 0：文件首，1：当前位置，2文件尾 
	*/
	fseek(fp,i*sizeof(struct stu),0);
	/**
	*	文件结束检测函数 
	*/
	printf("%d\n",feof(fp));
	/**
	*	读写文件出错检测函数 
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
