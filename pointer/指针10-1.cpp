#include<stdio.h>

main(){
 int a,b;
 //ָ�����pointer_1,pointer_2 
 //pointer_1,pointer_2����a,b�ĵ�ַ
 //*pointer_1,*pointer_2����a,b��ֵ 
 int *pointer_1,*pointer_2;
 a=100;b=10;
 pointer_1=&a;
 pointer_2=&b;
 printf("%d,%d\n",a,b); 
 printf("%d,%d\n",*pointer_1,*pointer_2); 
 printf("%d,%d\n",pointer_1,pointer_2);
} 
