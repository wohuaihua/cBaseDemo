#include<stdio.h>
#include<string.h>
#include<WCHAR.H>

void test(){
	char a='A';
	
	//���ַ��������ھ�̬�ڴ��в�ռ��7���ֽڣ�6���ֽڱ����ַ�������1���ֽڱ�����ֹ����0��
	char * p = "Hello!" ;
	//strlen���� 0  ���ո�Ҳ���㳤�ȡ� 
	printf("%d\n",strlen(p));
	
	//������Ϊ�����鱣����10���ֽڵĴ���ռ䡣 
	char b[10] ;
	printf("%d\n",sizeof(b));
    
    //sizeof  �����0  
	char c[] = "Hello!" ;
    printf("%d",sizeof(c));
    
    //�ַ����������ھ�̬�����ڴ��У�����ĩβ���0����������Ҫ7���ֽڵĴ���ռ䡣
    static char d[] = "Hello!" ;

}

//���ַ�
//typedef unsigned short wchar_t ;
//�޷��� ��������̬ ,����16λ��
void test01(){
	wchar_t a = 'A' ;
	printf("%c , %d\n",a,sizeof(a)); 
	
	//ע������ڵ�һ������ǰ��Ĵ�д��ĸL������long������
	//�⽫���߱��������ַ��������ַ����棭��ÿ���ַ�ռ��2���ֽڡ�
	//ͨ����ָ�����pҪռ��4���ֽڣ����ַ���������Ҫ14���ֽڣ�ÿ���ַ���Ҫ2���ֽڣ�ĩβ��0����Ҫ2���ֽڡ�
	wchar_t * b = L"Hello!" ;
	printf("%s\n",b);
	
	//һ������ǰ���L�ǳ���Ҫ����������������֮�����û�пո�ֻ�д���L����������֪������Ҫ���ַ�����Ϊÿ���ַ�2�ֽڡ�
	static wchar_t c[] = L"Hello!" ;
	printf("%d",sizeof(c));
	
	//��ͨ�����ǲ���Ҫ�ģ�C��������Ը��ַ��������䣬ʹ����Ϊ���ַ���
	wchar_t d = L'A' ;
	
}

//���ַ����ӿ⺯��
void test02(){
	wchar_t * pw = L"Hello!" ;
	//int length = strlen (pw) ;
	//printf("%d",length);
	
	int length=wcslen(pw);
	printf("%d\n",length);
	wprintf(pw,"%s");
	
}

int main(){
	test02();
}
