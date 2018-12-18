#include<stdio.h>
#define SQ(y) ((y)*(y))
main(){
	int i=1;
	while(i<=5){
		//宏定义，这里面运行了两次 i++ 
		printf("%d\n",SQ(i++)); 
    }
} 
