#define UNICODE
#define _UNICODE
#include <windows.h>
#include <tchar.h>

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow )
{
    const TCHAR *sz1 = TEXT("这是第一个程序！");
    const TCHAR *sz2 = TEXT("打招呼");
    MessageBox( NULL, sz1, sz2, MB_OK );

    return 0;
}


/* 
 * 输出乱码，没找到原因：
 * 可能是，文件编码，代码编码，显示编码之间的不匹配
 * 字面量前显式加‘L’将强制用Unicode编码
 * 
 * 乱码问题解决：
 * MessageBox() 分两个版本，char类型用MessageBoxA(),
 * wchar_t 类型用MessageBoxW().若配合TCHAR, 则
 * 用MessageBox()
 * 
 * 经过分析发现是宏定义的地方不走 #ifdef UNICODE 分支
 * 可能是编译选项设置的问题，但是不知道在哪里设置，所以
 * 自己动手定义一下Unicode就好了。 
 * 
 */