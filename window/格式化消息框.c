#include <windows.h>
#include <tchar.h>   
#include <stdio.h>   


/**
* CDECL  ��  __cdecl
* C����Ĭ�ϵĺ������÷�����
  ���в������ҵ���������ջ����Щ�����ɵ������������Ϊ�ֶ���ջ��
  �����ú�������Ҫ������ߴ��ݶ��ٲ����������ߴ��ݹ�����߹��ٵĲ�����
  ������ȫ��ͬ�Ĳ����������������׶εĴ���
*/        
int CDECL MessageBoxPrintf (TCHAR * szCaption, TCHAR * szFormat, ...){
        
    TCHAR   szBuffer [1024] ;
    //�����������һ��� 
    //���ڻ�ȡ��ȷ�������Ĳ����� 
    va_list pArgList ;

    // The va_start macro (defined in STDARG.H) is usually equivalent to:
    // pArgList = (char *) &szFormat + sizeof (szFormat) ;
	//��ȡ�ɱ�����б�ĵ�һ�������ĵ�ַ    
    va_start (pArgList, szFormat) ;
        
    // The last argument to wvsprintf points to the arguments
    
//	int _vsnprintf(char* str, size_t size, const char* format, va_list ap);
//	char *str [out],�����ɵĸ�ʽ�����ַ������������.
//	size_t size [in], str�ɽ��ܵ�����ַ���[1]  (���ֽ�����UNICODEһ���ַ������ֽ�),��ֹ��������Խ��.
//	const char *format [in], ָ�������ʽ���ַ�����������������Ҫ�ṩ�Ŀɱ���������͡�������˳��
//	va_list ap [in], va_list����. va:variable-argument:�ɱ����    
    _vsntprintf ( szBuffer, sizeof (szBuffer) / sizeof (TCHAR),
                   szFormat, pArgList) ;
        
    // The va_end macro just zeroes out pArgList for no good reason
        
    va_end (pArgList) ;
    return MessageBox (NULL, szBuffer, szCaption, 0) ;
}
        
int WINAPI WinMain (HINSTANCE hInstance,
	HINSTANCE hPrevInstance,PSTR szCmdLine, int iCmdShow){
		
    int cxScreen, cyScreen ;
    //��ͼ��Ϊ��λ��ʾ����Ѷ��ʾ�Ŀ�Ⱥ͸߶ȡ� 
    cxScreen = GetSystemMetrics (SM_CXSCREEN) ;
    cyScreen = GetSystemMetrics (SM_CYSCREEN) ;
    MessageBoxPrintf (TEXT("ScrnSize"),
		TEXT ("The screen is %i pixels wide by %i pixels high."),cxScreen, cyScreen) ;
    return 0 ;
}

