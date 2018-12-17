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
     //�ڶ����ֶ�(lpfnWndProc) �����������������������д�����ʹ�õĴ�����Ϣ�������ĵ�ַ�� 
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     						//����ͼ�깩����ʹ�á�
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     						//��������깩����ʹ�á�
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     						//ȡ��һ��ͼ�ζ�������������У���ȡ�û��ƴ��ڱ����Ļ�ˢ���󣩡�
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ;
		//Ϊ���򴰿�ע�ᴰ�����
     if (!RegisterClass (&wndclass))
     {		
     	  //��ʾ��Ϣ��
          MessageBox (NULL, TEXT ("This program requires Windows NT!"), 
                      szAppName, MB_ICONERROR) ;
          return 0 ;
     }
    		//���ݴ��������һ�����ڡ�
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
     //����Ļ����ʾ���ڡ�
     ShowWindow (hwnd, iCmdShow) ;
     //ָʾ�������Ҹ��¡�
     UpdateWindow (hwnd) ;
     		//����Ϣ������ȡ����Ϣ��
     while (GetMessage (&msg, NULL, 0, 0))
     {	
     	  //ת��ĳЩ������Ϣ��
          TranslateMessage (&msg) ;
          //����Ϣ���͸�������Ϣ�������
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
     	  //����һ�������ļ���
          PlaySound (TEXT ("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
          return 0 ;
          
     case WM_PAINT:
     			//��ʼ���ƴ��ڡ�
          hdc = BeginPaint (hwnd, &ps) ;
          //ȡ�ô�����ʾ����Ĵ�С��
          GetClientRect (hwnd, &rect) ;
          //��ʾ�ַ�����
          DrawText (hdc, TEXT ("Hello, Windows 98!"), -1, &rect,
                    DT_SINGLELINE | DT_CENTER | DT_VCENTER) ;
          //����Ϣ�����в���һ�����˳�������Ϣ��
          EndPaint (hwnd, &ps) ;
          return 0 ;
          
     case WM_DESTROY:
          PostQuitMessage (0) ;
          return 0 ;
     }
     		//ִ���ڶ�����Ϣ����
     return DefWindowProc (hwnd, message, wParam, lParam) ;
}
