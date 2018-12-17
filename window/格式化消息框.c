#include <windows.h>
#include <tchar.h>   
#include <stdio.h>   


/**
* CDECL  和  __cdecl
* C语言默认的函数调用方法：
  所有参数从右到左依次入栈，这些参数由调用者清除，称为手动清栈。
  被调用函数不会要求调用者传递多少参数，调用者传递过多或者过少的参数，
  甚至完全不同的参数都不会产生编译阶段的错误。
*/        
int CDECL MessageBoxPrintf (TCHAR * szCaption, TCHAR * szFormat, ...){
        
    TCHAR   szBuffer [1024] ;
    //解决变参问题的一组宏 
    //用于获取不确定个数的参数。 
    va_list pArgList ;

    // The va_start macro (defined in STDARG.H) is usually equivalent to:
    // pArgList = (char *) &szFormat + sizeof (szFormat) ;
	//获取可变参数列表的第一个参数的地址    
    va_start (pArgList, szFormat) ;
        
    // The last argument to wvsprintf points to the arguments
    
//	int _vsnprintf(char* str, size_t size, const char* format, va_list ap);
//	char *str [out],把生成的格式化的字符串存放在这里.
//	size_t size [in], str可接受的最大字符数[1]  (非字节数，UNICODE一个字符两个字节),防止产生数组越界.
//	const char *format [in], 指定输出格式的字符串，它决定了你需要提供的可变参数的类型、个数和顺序。
//	va_list ap [in], va_list变量. va:variable-argument:可变参数    
    _vsntprintf ( szBuffer, sizeof (szBuffer) / sizeof (TCHAR),
                   szFormat, pArgList) ;
        
    // The va_end macro just zeroes out pArgList for no good reason
        
    va_end (pArgList) ;
    return MessageBox (NULL, szBuffer, szCaption, 0) ;
}
        
int WINAPI WinMain (HINSTANCE hInstance,
	HINSTANCE hPrevInstance,PSTR szCmdLine, int iCmdShow){
		
    int cxScreen, cyScreen ;
    //以图素为单位显示了视讯显示的宽度和高度。 
    cxScreen = GetSystemMetrics (SM_CXSCREEN) ;
    cyScreen = GetSystemMetrics (SM_CYSCREEN) ;
    MessageBoxPrintf (TEXT("ScrnSize"),
		TEXT ("The screen is %i pixels wide by %i pixels high."),cxScreen, cyScreen) ;
    return 0 ;
}

