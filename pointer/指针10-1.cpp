#include<stdio.h>

main(){
 int a,b;
 //指针变量pointer_1,pointer_2 
 //pointer_1,pointer_2代表a,b的地址
 //*pointer_1,*pointer_2代表a,b的值 
 int *pointer_1,*pointer_2;
 a=100;b=10;
 pointer_1=&a;
 pointer_2=&b;
 printf("%d,%d\n",a,b); 
 printf("%d,%d\n",*pointer_1,*pointer_2); 
 printf("%d,%d\n",pointer_1,pointer_2);
} 
