#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	FILE *f;
	char ch;
	if((f=fopen("C:\\Users\\76494\\Desktop\\�½�.txt","wt+"))==NULL){
		printf("Cannot open file strike any key exit!");
		getch();
		exit(1);
	}
	printf("input a string:\n");
	//getchar()������STDIN(��׼����)��ȡ��������һ���ַ�,��������ļ�β����EOF.  
	ch=getchar();
	
	//ch!="\n"  ������������� 
	while(ch!='\n'){
		fputc(ch,f);
		ch=getchar();
	}
	//���ļ���ָ�룬ָ���ļ���ʼ�� 
	rewind(f);
	ch=fgetc(f);
	while(ch!=EOF){
		putchar(ch);
		ch=fgetc(f); 
	} 
	printf("\n");
	fclose(f);
	return 0;
}
