#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

main(){
	FILE *fp;
	char str[11];
	if((fp=fopen("C:\\Users\\76494\\Desktop\\copy.txt","r"))==NULL){
		printf("\nCannot open file strike any key exit!"); 
		getch(); 
		exit(1);
	}
	fgets(str,11,fp);
	printf("\n%s\n",str);
	fclose(fp);
}
