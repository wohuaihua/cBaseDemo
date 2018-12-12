#include <stdio.h>
#include<io.h>
#include <string.h>
#include <stdlib.h>

#define PATH ".\\*.exe"


//������ȡ����·��
//���ﴦ�������ַ��������� 
//strcat ƴ�������ʱ��Ҳ�������� 
char * fatherPath(){
	int index=0;
	int length=strlen(PATH);
	int i=0;
	for(i=0;i<length;i++){
		if('\\'==PATH[i]){
			index=i;	
		}
	}
	char * fatherPath=malloc(sizeof(char)*index);
	//һ��Ҫ������� 
	memset(fatherPath,0,index);
	for(i=0;i<index;i++){
		fatherPath[i]=PATH[i];
		//printf("->%c\n",PATH[i]);
	}
	//printf("%s\n",fatherPath);
	return  fatherPath;
}

int getPathCharNums(){
	int index=0;
	int length=strlen(PATH);
	int i=0;
	for(i=0;i<length;i++){
		if('\\'==PATH[i]){
			index=i;	
		}
	}
	return index;
}


//����һ���ļ����±ߵ��ļ���Ŀ
//char * path  �ļ��е�ַ 
int filesNum(struct _finddata_t fileinfo,long fHandle){
	int fileNum = 0;
	if((fHandle=_findfirst(PATH, &fileinfo )) == -1L ) 
    {
        printf( "��ǰĿ¼��û��txt�ļ�\n");
        return 0;
    }
    else{
        do{
            fileNum ++;
        }while( _findnext(fHandle,&fileinfo)==0);
    }
    _findclose( fHandle );
    return fileNum;
}

//��ȡһ���ļ����±ߵ������ļ��� 
char ** getFileNames(struct _finddata_t fileinfo,long fHandle,int fileNum){
	fHandle=_findfirst(PATH, &fileinfo );
	char ** fileNames=malloc(sizeof(char *)* fileNum);
	int j=0;
    do{
    	fileNames[j]=malloc(sizeof(char)* 260);
    	strcpy(fileNames[j],fileinfo.name);
    	j++;
    }while( _findnext(fHandle,&fileinfo)==0);
    _findclose( fHandle );
    return fileNames;
} 

//ɾ��һ���ļ����±ߵ������ļ� 
//char ** fileNames	�ļ�������
//int fileNum �ļ���Ŀ 
int deleteFiles(char ** fileNames,int fileNum){
	printf("\nɾ���ļ� \n");
	int j=0;
	for(j=0;j<fileNum;j++){
    	if(remove(fileNames[j])==0){
    		printf("-> ɾ���ļ� : %s\n",fileNames[j]);
    		continue;
		}
		printf("\t-> ɾ��ʧ�� : %s\n",fileNames[j]);
		perror("ʧ��"); 
	} 
} 

void freeSpace(char ** fileNames,int filesNum){
	printf("\n �ͷ��ڴ�\n");
	int i=0;
	for(i=0;i<filesNum;i++){
		if(fileNames[i]!=NULL){
			free(fileNames[i]);
			fileNames[i]=NULL;
		}
	}
	if(fileNames!=NULL){
		free(fileNames);
		fileNames=NULL;
	}
}

void printfFilesName(char ** fileNames,int filesNum){
	printf("����չʾ \n");
	int i=0;
	for(i=0;i<filesNum;i++){
		printf("\t-> %s\n",fileNames[i]);
	}
}

int main(void)
{
    //�ļ��洢��Ϣ�ṹ�� 
    struct _finddata_t fileinfo;
    //�����ļ���� 
    long fHandle;
    //�ļ�����¼��
    int fileNum = 0;
    char ** fileNames;
    fileNum=filesNum(fileinfo,fHandle);
    fileNames=getFileNames(fileinfo,fHandle,fileNum);
	printfFilesName(fileNames,fileNum);    
    deleteFiles(fileNames,fileNum);
    freeSpace(fileNames,fileNum);
    system("pause");
    return 0;
}

