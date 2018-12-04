# include <stdio.h>
# include <stdlib.h> 

int main(void){
	//发出一个DOS命令
	//在windows下的system函数中命令可以不区别大小写 
	system("dir");
	printf("%s","pause");
} 
