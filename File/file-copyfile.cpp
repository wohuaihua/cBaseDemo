#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//用于存放命令行参数的个数
//命令行中的每一个参数
int main(int argc,char *argv[]){
	FILE *fp1,*fp2;
	char ch;
	printf("%d \n",argc);
	printf("%s \n",argv[0]);
	if(argc==1){
		printf("have not enter file name strike any key exit");
		getch();
		exit(1);
	}
	
	if((fp1=fopen(argv[1],"rt"))==NULL){
		printf("Cannot open %s\n",argv[1]);
		getch();
		exit(1);
	}
	//标准输出文件
	if(argc==2) fp2=stdout;
	else if((fp2=fopen(argv[2],"wt+"))==NULL){
		printf("");
		getch();
		exit(1); 
	}
	while((ch=fgetc(fp1))!=EOF){
		fputc(ch,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
} 
