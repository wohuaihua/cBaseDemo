#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	char ch,str[20];
	
	//a ��� t �ı� + ����д 
	if((fp=fopen("C:\\Users\\76494\\Desktop\\�½�.txt","at+"))==NULL){
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
		//ֱ���������׼����ļ� ����Ļ�� 
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);
}
