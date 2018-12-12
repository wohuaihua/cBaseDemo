#include <stdio.h>
#include<io.h>
#include <string.h>
#include <stdlib.h>

#define PATH "D:\\WorkProject\\cBaseDemo\\���\\*.exe"


//������ȡ����·�� 
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
	memset(fatherPath, '\0',index);
	for(i=0;i<index+1;i++){
		fatherPath[i]=PATH[i];
	}
	//printf("%s\n",fatherPath);
	return  fatherPath;
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
	int j=0;
	char * path=fatherPath();
	printf("%s\n",path);
	
	for(j=0;j<fileNum;j++){
		//char * temp=strcat(fatherPath(),fileNames[j]);
		printf("%s\n",fileNames[j]);
    	if(1){
    		//printf("-> ɾ���ļ� : %s\n",path);
    		continue;
		}
		//printf("\t-> ɾ��ʧ�� : %s\n",path);
	} 
} 

void freeSpace(char ** fileNames,int filesNum){
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
	int i=0;
	for(i=0;i<filesNum;i++){
		printf("%s\n",fileNames[i]);
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
	//printfFilesName(fileNames,fileNum);    
    deleteFiles(fileNames,fileNum);
    freeSpace(fileNames,fileNum);
    return 0;
}

