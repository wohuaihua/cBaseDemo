#include <stdio.h>
#include<io.h>
#include <string.h>
#include <stdlib.h>

#define PATH "D:\\WorkProject\\cBaseDemo\\提高\\*.exe"


//用来获取父亲路径 
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
	//一定要清空数组 
	memset(fatherPath, '\0',index);
	for(i=0;i<index+1;i++){
		fatherPath[i]=PATH[i];
	}
	//printf("%s\n",fatherPath);
	return  fatherPath;
}


//返回一个文件加下边的文件数目
//char * path  文件夹地址 
int filesNum(struct _finddata_t fileinfo,long fHandle){
	int fileNum = 0;
	if((fHandle=_findfirst(PATH, &fileinfo )) == -1L ) 
    {
        printf( "当前目录下没有txt文件\n");
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

//获取一个文件夹下边的所有文件名 
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

//删除一个文件夹下边的素有文件 
//char ** fileNames	文件名集合
//int fileNum 文件数目 
int deleteFiles(char ** fileNames,int fileNum){
	int j=0;
	char * path=fatherPath();
	printf("%s\n",path);
	
	for(j=0;j<fileNum;j++){
		//char * temp=strcat(fatherPath(),fileNames[j]);
		printf("%s\n",fileNames[j]);
    	if(1){
    		//printf("-> 删除文件 : %s\n",path);
    		continue;
		}
		//printf("\t-> 删除失败 : %s\n",path);
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
    //文件存储信息结构体 
    struct _finddata_t fileinfo;
    //保存文件句柄 
    long fHandle;
    //文件数记录器
    int fileNum = 0;
    char ** fileNames;
    fileNum=filesNum(fileinfo,fHandle);
    fileNames=getFileNames(fileinfo,fHandle,fileNum);
	//printfFilesName(fileNames,fileNum);    
    deleteFiles(fileNames,fileNum);
    freeSpace(fileNames,fileNum);
    return 0;
}

