#include<stdio.h>

main(){
	int *p1,*p2,*p,a,b;
	scanf("%d %d",&a,&b);
	//ָ�����p1,p2,����&a,&b�ĵ�ַ 
	p1=&a;p2=&b;
	//����ǵ�ַ���� 
	if(a<b){
		p=p1;
		p1=p2;
		p2=p;
	} 
	printf("\na=%d,b=%d\n",a,b);
	printf("max=%d,min=%d\n",*p1,*p2);
}
