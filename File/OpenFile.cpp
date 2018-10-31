# include<stdio.h>
# include<conio.h>
# include<cstdlib>
main() {
	FILE *fp;
	char ch;
	if((fp=fopen("C:\\Users\\76494\\Desktop\\poc.txt","r"))==NULL) {
		printf("\nCannot open file strike any key exit!");
		//当用户按下某个字符时，函数自动读取，无需按回车
		getch();
		//终止程序的执行。参数exit_code 传递给返回值，通常零值表示正常结束，非零值表示应错误返回。
		exit(1);
	}
	//fgetc()函数返回来自stream(流)中的下一个字符,如果到达文件尾或者发生错误时返回EOF.  
	ch=fgetc(fp);
	
	while(ch!=EOF) {
		//putchar()函数把ch写到STDOUT(标准输出)
		putchar(ch);
		ch=fgetc(fp);
	}
	//函数fclose()关闭给出的文件流, 释放已关联到流的所有缓冲区. fclose()执行成功时返回0,否则返回EOF.  
	fclose(fp);
}
