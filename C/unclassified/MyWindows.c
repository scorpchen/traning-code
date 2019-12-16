#define UNICODE
#define _UNICODE
#include <windows.h>

LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow )
{
    static TCHAR szAppName[] = TEXT("MyWindows");
    HWND hwnd;                                                                                              // 窗口句柄
    MSG msg;                                                                                                // 消息结构
    WNDCLASS wndclass;                                                                                      // 窗口类结构

    wndclass.style = CS_HREDRAW | CS_VREDRAW;                                                               // 调整宽度重绘，调整高度重绘
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wndclass.hCursor = LoadCursor( NULL, IDC_ARROW );                                                       // 光标
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    if ( !RegisterClass(&wndclass) ){                                                                       // 注册窗口
        MessageBox(NULL, TEXT("这个程序需要在windowsNT环境下执行！"), szAppName, MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindow(szAppName,                                                                          // 生成窗口
                        TEXT("南泊湾"),
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        NULL,
                        NULL,
                        hInstance,
                        NULL
                        );

    ShowWindow(hwnd, iCmdShow);                                                                             // 显示窗口
    UpdateWindow(hwnd);                                                                                     // 更新窗口

    while ( GetMessage( &msg, NULL, 0, 0 ) ){                                                               // 消息循环
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }
    
    return msg.wParam;
}

LRESULT CALLBACK WndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;

    switch ( message ){
        case WM_PAINT:
            hdc = BeginPaint( hwnd, &ps );
            GetClientRect( hwnd, &rect );
            DrawText(hdc, TEXT("哦哟"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
            EndPaint(hwnd, &ps);
            return 0;
        case WM_LBUTTONDOWN:
            MessageBox( hwnd, TEXT("哎呀~"), TEXT("哦哟~"), MB_OK);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}





// 需要连接libgdi32库       -lgdi32



/* 
 * 许多 Windows 程序员都使用“匈牙利标记法”作为变量命名约定。这是为了纪念具有传奇色彩的微软程序员 Charles Simonyi。
 * 这种标记法非常简单，即变量名以一个或者多个小写字母开始，这些字母表示变量的数据型态。例如：szCmdLine 中的 sz 代
 * 表“以0结尾的字符串（StringZero）”；在 hInstance 和 hPrevInstance 中的 h 前缀表示“句柄（Handle）”；在 iCmdShow 
 * 中的 i 前缀表示“整型（Integer）”。
 * 当命名结构变量时，可以用结构名（或者结构名的一种缩写）的小写形式作为变量名称的前缀，或者用作整个变量名。例如：
 * msg 变量是 MSG 型态的结构；wndclass 是 WNDCLASSEX 型态的一个结构；ps 是一个 PAINTSTRUCT 结构，rect 是一个 RECT 
 * 结构。
 * 匈牙利表示法能够帮助程序写作者及早发现并避免程序中的错误。由于变量名既描述了变量的作用，又描述了其数据型态，就比较
 * 容易避免产生数据型态不合的错误。

常见的前缀：
    c	char 或 WCHAR 或 TCHAR
    by	BYTE （无符号字符）
    n	short（短整型）
    i	int（整型）
    x, y	int，表示 x 坐标和 y 坐标
    cx, cy	int，表示 x 或 y 的长度，c 表示“count”（计数）
    B 或 f	BOOL（int）；f 表示“flag”
    w	WORD（无符号短整型）
    l	LONG（长整型）
    dw	DWORD（无符号长整型）
    fn	函数
    s	字符串
    sz	以零结束的字符串
    h	句柄
    p	指针
*/

/* 
 * 在 Winodows 的定义中包含着许多大写标识符，这些标识符有很多都是以两个或三个字母作为前缀，且其后紧跟一个下划线
 
 常见的前缀：
    CS	类风格选项（ClassStyle）
    CW	创建窗口选项（CreateWindow）
    DT	文本绘制选项（DrawText）
    IDI	图标的 ID 号（IDIcon）
    IDC	光标的 ID 号（IDCursor）
    MB	消息框选项（MessageBox）
    SND	声音选项（Sound）
    WM	窗口消息（WindowsMessage）
    WS	窗口风格（WindowStyles）
*/