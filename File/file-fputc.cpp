#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	FILE *f;
	char ch;
	if((f=fopen("C:\\Users\\76494\\Desktop\\新建.txt","wt+"))==NULL){
		printf("Cannot open file strike any key exit!");
		getch();
		exit(1);
	}
	printf("input a string:\n");
	//getchar()函数从STDIN(标准输入)获取并返回下一个字符,如果到达文件尾返回EOF.  
	ch=getchar();
	
	//ch!="\n"  这样是有问题的 
	while(ch!='\n'){
		fputc(ch,f);
		ch=getchar();
	}
	//将文件内指针，指到文件开始处 
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
