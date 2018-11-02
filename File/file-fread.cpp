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
	//这个是数组， 
	pp=boya;
	qq=boyb;
	
	if((fp=fopen("C:\\Users\\hzh\\Desktop\\stu","wb+"))==NULL){
		printf("Cannot open file strike any key exit!"); 
		getch(); 
		exit(1);
	}
<<<<<<< HEAD
	printf("\ninput data\n");
=======
	printf("input data\n");
>>>>>>> c263965a7f764eda41b858c22af91888ff003ce8
	for(i=0;i<2;i++,pp++){
		scanf("%s%d%d%s",pp->name,&pp->num,&pp->age,pp->addr);
	}
	pp=boya;
	//sizeof计算右边表达式并返回字节数 
	fwrite(pp,sizeof(struct stu),2,fp);
	rewind(fp);
	fread(qq,sizeof(struct stu),2,fp);
<<<<<<< HEAD
	printf("\n\nname\tnumber\tage\taddr\n");
=======
	printf("\nname\tnumber\tage\taddr\n");
>>>>>>> c263965a7f764eda41b858c22af91888ff003ce8
	for(i=0;i<2;i++,qq++){
		printf("%s\t%d\t%d%\t%s\n",qq->name,qq->num,qq->age,qq->addr);
	}
	fclose(fp);
} 
