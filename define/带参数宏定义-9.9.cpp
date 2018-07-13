#include<stdio.h>

//如果使用main函数后面的函数，那么需在前面进行函数声明。
//函数声明
int SQ(int y);

main() {
	int i=1;
	while(i<=5) {
		printf("%d\n",SQ(i++));
	}
}

int SQ(int y) {
	return ((y)*(y));
}
