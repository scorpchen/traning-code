/****************************************************************************
 * 
 * 11.
 * getsputs.c
 * 使用gets（）和 puts（）
 * 由于gets()函数无法检测目标空间的大小，有可能导致缓冲区溢出
 * 所以后面有了替代品fgets（）和 fputs（）
 * 
 ****************************************************************************/

#include <stdio.h>

#define STLEN 81

int main( void )
{
    char words[STLEN];

    puts("Enter a string, please.");            // puts() 函数会自动在末尾添加换行符
    gets(words);                                // 只有目标空间的地址这一个参数; gets()函数遇到\n停止，并将\n丢弃
    printf("Your string twice:\n");
    printf("%s\n", words);
    puts(words);
    puts("Done.");

    return 0;
    }

