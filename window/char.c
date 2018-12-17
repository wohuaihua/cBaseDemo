#include<stdio.h>
#include<string.h>
#include<WCHAR.H>
#include<tchar.h>

#define _UNICODE 1

void test(){
	char a='A';
	
	//该字符串保存在静态内存中并占用7个字节－6个字节保存字符串，另1个字节保存终止符号0。
	char * p = "Hello!" ;
	//strlen不算 0  ，空格也计算长度。 
	printf("%d\n",strlen(p));
	
	//编译器为该数组保留了10个字节的储存空间。 
	char b[10] ;
	printf("%d\n",sizeof(b));
    
    //sizeof  会计算0  
	char c[] = "Hello!" ;
    printf("%d",sizeof(c));
    
    //字符串都储存在静态程序内存中，并在末尾添加0，这样就需要7个字节的储存空间。
    static char d[] = "Hello!" ;

}

//宽字符
//typedef unsigned short wchar_t ;
//无符号 短整数型态 ,都是16位宽
void test01(){
	wchar_t a = 'A' ;
	printf("%c , %d\n",a,sizeof(a)); 
	
	//注意紧接在第一个引号前面的大写字母L（代表「long」）。
	//这将告诉编译器该字符串按宽字符保存－即每个字符占用2个字节。
	//通常，指针变量p要占用4个字节，而字符串变量需要14个字节－每个字符需要2个字节，末尾的0还需要2个字节。
	wchar_t * b = L"Hello!" ;
	printf("%s\n",b);
	
	//一个引号前面的L非常重要，并且在两个符号之间必须没有空格。只有带有L，编译器才知道您需要将字符串存为每个字符2字节。
	static wchar_t c[] = L"Hello!" ;
	printf("%d\n",sizeof(c));
	
	//但通常这是不必要的，C编译器会对该字符进行扩充，使它成为宽字符。
	wchar_t d = L'A' ;
	printf("%d\n",sizeof(d)); 
	
}

//宽字符链接库函数
void test02(){
	wchar_t * pw = L"Hello!" ;
	//int length = strlen (pw) ;
	//printf("%d",length);
	
	int length=wcslen(pw);
	printf("%d\n",length);
	wprintf(pw,"%s");
	
}

void test03(){
	printf ("The sum of %i and %i is %i\n", 5, 3, 5+3) ;
	
	char szBuffer [100] ;
    //第一个参数是字符缓冲区；后面是一个格式字符串。
	//Sprintf不是将格式化结果标准输出，而是将其存入szBuffer。    
	sprintf (szBuffer, "The sum of %i and %i is %i\n", 5, 3, 5+3) ;
        
	puts (szBuffer) ;
}

void test04(){
	printf("%d",sizeof(TCHAR));
}

//中文 
void test05(){
	char a[]="胡爱华ABCD";
	printf("%s\n",a);
	printf("%d\n",sizeof(a));
	printf("%d\n",strlen(a)); 
}

void test06(){
	TCHAR a[]=_T("胡爱华ABCD");
	printf("%d\n",_tcslen(a));
	printf("%d\n",wcslen(a));
}

int main(){
	test06();
}
