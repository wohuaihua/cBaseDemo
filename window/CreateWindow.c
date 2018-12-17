#include <windows.h>
 
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     static TCHAR szAppName[] = TEXT ("HelloWin") ;
     HWND         hwnd ;
     MSG          msg ;
     WNDCLASS     wndclass ;

     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
     //第二个字段(lpfnWndProc) 是依据这个类别来建立的所有窗口所使用的窗口消息处理程序的地址。 
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     						//加载图标供程序使用。
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     						//加载鼠标光标供程序使用。
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     						//取得一个图形对象（在这个例子中，是取得绘制窗口背景的画刷对象）。
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ;
		//为程序窗口注册窗口类别。
     if (!RegisterClass (&wndclass))
     {		
     	  //显示消息框。
          MessageBox (NULL, TEXT ("This program requires Windows NT!"), 
                      szAppName, MB_ICONERROR) ;
          return 0 ;
     }
    		//根据窗口类别建立一个窗口。
     hwnd = CreateWindow (szAppName,                  // window class name
                          TEXT ("The Hello Program"), // window caption
                          WS_OVERLAPPEDWINDOW,        // window style
                          CW_USEDEFAULT,              // initial x position
                          CW_USEDEFAULT,              // initial y position
                          CW_USEDEFAULT,              // initial x size
                          CW_USEDEFAULT,              // initial y size
                          NULL,                       // parent window handle
                          NULL,                       // window menu handle
                          hInstance,                  // program instance handle
                          NULL) ;                     // creation parameters
     //在屏幕上显示窗口。
     ShowWindow (hwnd, iCmdShow) ;
     //指示窗口自我更新。
     UpdateWindow (hwnd) ;
     		//从消息队列中取得消息。
     while (GetMessage (&msg, NULL, 0, 0))
     {	
     	  //转译某些键盘消息。
          TranslateMessage (&msg) ;
          //将消息发送给窗口消息处理程序。
          DispatchMessage (&msg) ;
     }
     return msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     HDC         hdc ;
     PAINTSTRUCT ps ;
     RECT        rect ;
     
     switch (message)
     {
     case WM_CREATE:
     	  //播放一个声音文件。
          PlaySound (TEXT ("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
          return 0 ;
          
     case WM_PAINT:
     			//开始绘制窗口。
          hdc = BeginPaint (hwnd, &ps) ;
          //取得窗口显示区域的大小。
          GetClientRect (hwnd, &rect) ;
          //显示字符串。
          DrawText (hdc, TEXT ("Hello, Windows 98!"), -1, &rect,
                    DT_SINGLELINE | DT_CENTER | DT_VCENTER) ;
          //在消息队列中插入一个「退出程序」消息。
          EndPaint (hwnd, &ps) ;
          return 0 ;
          
     case WM_DESTROY:
          PostQuitMessage (0) ;
          return 0 ;
     }
     		//执行内定的消息处理。
     return DefWindowProc (hwnd, message, wParam, lParam) ;
}
