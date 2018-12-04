#include<stdio.h>
#include <string.h>
#include <stdlib.h>


int getFileLine(FILE * file){
	if(file==NULL){
		return -1;
	}
	char buf[1024];
	int lineNum=0;
	while(fgets(buf,1024,file)!=NULL){
		lineNum++;
	}
	//把文件指针移到由stream(流)指定的开始处, 同时清除和流相关的错误和EOF标记。 
	rewind(file);
	return lineNum;
}

void readFileData(char ** p,int lineNum,FILE * file){
	
	if(p==NULL){
		return ;
	}
	if(lineNum<1){
		return ;
	}
	if(file==NULL){
		return ;
	}
	int i=0;
	char buf[1024]; 
	
	//for(i=0;i<lineNum;i++){
	//	fgets(buf,1024,file);
	//	printf("%s",buf);
	//}
	
	int lineIndex=0; 
	while(fgets(buf,1024,file)!=NULL){
		//返回字符串str 的长度( 即空值结束符之前字符数目)。
		int currentLineLength=strlen(buf)+1;
		char * currentChar=malloc(sizeof(char)*currentLineLength);
		//TODO 验证是否可行 
		//*currentChar=buf;
		
		//将数据拷贝到堆中 
		//复制字符串from 中的字符到字符串to，包括空值结束符。返回值为指针to。
		strcpy(currentChar,buf) ;
		*p[lineIndex]=currentChar;
		lineIndex++;
		
		memset(buf,0,1024);
	} 
	rewind(file);
}

void showFileData(char ** p,int lineNum){
	int i=0;
	for(i=0;i<lineNum;i++){
		printf("行%n数据%s\n",i+1,p[i]);
	}
}

void test(){
	FILE * file=fopen("./readfile.txt","r");
	if(file==NULL){
		printf("%s\n","文件打开失败");
		return ;
	}
	int lineNum=getFileLine(file);
	char ** p=malloc(sizeof(char *)*lineNum);
	//将文件中的数据，读取后，放入p中 ,lineNum为有效行数 
	readFileData(p,lineNum,file);
	showFileData(p,lineNum);
} 


int main(){
	test();
		
} 
