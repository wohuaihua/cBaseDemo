#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectSort(char ** p,int length){
	int i=0;
	for(i=0;i<length;i++){
		printf("%s\n",*(p+length-i-1));
	}
}

void selectSort01(char * arr[],int length){
	int i=0;
	for(i=0;i<length;i++){
		printf("%s\n",arr[length-i-1]);
	}
}

void selectSortChar01(char * arr[],int length){
	int i=0;
	for(i=0;i<length;i++){
		int min=i;
		int j;
		for(j=i+1;j<length;j++){
			if(strcmp(arr[min],arr[j])>0){
				min=j;
			}
		}
		if(min!=i){
			char * temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		} 
	}
	
	for(i=0;i<length;i++){
		printf("%s\n",arr[i]);
	}
}


void test(){
	char * arr[]={"aaa","ggg","bbb","ppp","iii"};
	printf("%d\n",sizeof(char *));
	int lenght=sizeof(arr) / sizeof(char *); 
	selectSortChar01(arr,lenght);
} 

void selectSortInt(int * p,int length){
	int i=0;
	for(i=0;i<length;i++){
		int min=i;
		int j;
		for(j=i+1;j<length;j++){
			if(*(p+min)>*(p+j)){
				min=j;
			}
		}
		if(min!=i){
//			int temp=*(p+i);
//			*(p+i)=*(p+min);
//			*(p+min)=temp;

			*(p+i)=	*(p+i)^*(p+min);
			*(p+min)=*(p+i)^*(p+min);
			*(p+i)=	*(p+i)^*(p+min);	
		}
	}
	for(i=0;i<length;i++){
		printf("%d\n",*(p+i));
	}
}

void selectSortInt01(int arr[],int length){
	int i=0;
	for(i=0;i<length;i++){
		int min=i;
		int j;
		for(j=i+1;j<length;j++){
			if(arr[min]>arr[j]){
				min=j;
			}
		}
		if(min!=i){
			int temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		} 
	}
	
	for(i=0;i<length;i++){
		printf("%d\n",arr[i]);
	}
}

void test01(){
	int arr[]={11,3,4,2,5,6,3};
	int length=sizeof(arr)/sizeof(int);
	selectSortInt(arr,length);
	//selectSortInt01(arr,length);
}
int main(){
	test();
} 
