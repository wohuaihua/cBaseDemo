#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct stu{
		char name[10];
		int num;
		int age;
		char addr[15];	
	}boya[2],boyb[2],*pp,*qq;

main(){
	FILE *fp;
	char ch;
	int i;
	pp=boya;
	qq=boyb;
	if((fp=fopen("C:\\Users\\76494\\Desktop\\stu","wb+"))==NULL){
		printf("Cannot open file strike any key exit!"); 
		getch(); 
		exit(1);
	}
	printf("\ninput data\n");
	for(i=0;i<2;i++){
		scanf("%s%d%d%s",pp->name,&pp->num,&pp->age,pp->addr);
	}
	pp=boya;
	//sizeof�����ұ߱��ʽ�������ֽ��� 
	fwrite(pp,sizeof(struct stu),2,fp);
	rewind(fp);
	fread(qq,sizeof(struct stu),2,fp);
	printf("\n\nname\tnumber	age		addr\n");
	for(i=0;i<2;i++,qq++){
		printf("%s\t%5d%7d	%s\n",qq->name,qq->num,qq->age,qq->addr);
	}
	fclose(fp);
} 
