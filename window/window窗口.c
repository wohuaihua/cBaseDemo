#include <windows.h>

/**
*	WINAPI
	#define WINAPI __stdcall
	该语句指定了一个呼叫约定，包括如何生产机械码以在堆栈中放置函数呼叫的参数。
	许多Windows函数呼叫声明为WINAPI。


	HINSTANCE hInstance  第一个参数被称作「执行实体句柄」
	句柄仅是一个应用程序用来识别某些东西的数字
	
	当同时运行同一程序多次时，您便创建了该程序的「多个执行实体（multiple instances）」
	同一应用程序的所有执行实体共享程序和只读的内存
	hPrevInstance参数就能够确定自身的其它执行实体是否正在运行 
	在32位Windows版本中，该概念已被抛弃。传给WinMain的第二个参数总是NULL（定义为0）。
	
	
	PSTR szCmdLine
	第三个参数是用于执行程序的命令列。某些Windows应用程序利用它在程序启动时将文件加载内存。
	
	int iCmdShow 第四个参数指出程序最初显示的方式，可
	以是正常的或者是最大化地充满整个画面，或者是最小化显示在工作列中。
*/ 

int WINAPI WinMain (HINSTANCE hInstance,
	HINSTANCE hPrevInstance,PSTR szCmdLine, int iCmdShow){
		
	/**
	*	MessageBox函数用于显示短信息，它被认为是一个对话框。
		
		第一个参数通常是窗口句柄
		
		第二个参数是在消息框主体中显示的字符串
		
		第三个参数是出现在消息框标题列上的字符串
		这些文字字符串的每一个都被封装在一个TEXT宏中。
		通常您不必将所有字符串都封装在TEXT宏中，但如果想将您的程序转换为Unicode字符集，这确是一个好主意。 
		
		第四个参数可以是在WINUSER.H中定义的一组以前缀MB_开始的常数的组合
	*/
	 
	MessageBox (NULL, TEXT("Hello, Windows 98!"), TEXT("HelloMsg"), MB_OK|MB_DEFBUTTON3|MB_ICONHAND);
	return 0 ;
}

