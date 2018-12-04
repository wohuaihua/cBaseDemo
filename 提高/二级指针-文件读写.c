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
	//���ļ�ָ���Ƶ���stream(��)ָ���Ŀ�ʼ��, ͬʱ���������صĴ����EOF��ǡ� 
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
		//�����ַ���str �ĳ���( ����ֵ������֮ǰ�ַ���Ŀ)��
		int currentLineLength=strlen(buf)+1;
		char * currentChar=malloc(sizeof(char)*currentLineLength);
		//TODO ��֤�Ƿ���� 
		//*currentChar=buf;
		
		//�����ݿ��������� 
		//�����ַ���from �е��ַ����ַ���to��������ֵ������������ֵΪָ��to��
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
		printf("��%n����%s\n",i+1,p[i]);
	}
}

void test(){
	FILE * file=fopen("./readfile.txt","r");
	if(file==NULL){
		printf("%s\n","�ļ���ʧ��");
		return ;
	}
	int lineNum=getFileLine(file);
	char ** p=malloc(sizeof(char *)*lineNum);
	//���ļ��е����ݣ���ȡ�󣬷���p�� ,lineNumΪ��Ч���� 
	readFileData(p,lineNum,file);
	showFileData(p,lineNum);
} 


int main(){
	test();
		
} 
