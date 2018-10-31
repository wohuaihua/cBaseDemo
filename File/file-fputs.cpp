#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	char ch,str[20];
	
	//a 添加 t 文本 + 读和写 
	if((fp=fopen("C:\\Users\\76494\\Desktop\\新建.txt","at+"))==NULL){
		printf("Cannot open file strike any key exit!"); 
		getch(); 
		exit(1);
	}
	
	printf("intput a string :\n");
	scanf("%s",str);
	fputs(str,fp);
	rewind(fp);
	ch=fgetc(fp);
	while(ch!=EOF){
		//直接输出到标准输出文件 （屏幕） 
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);
}
