/****************************************************************************
 * 
 * 11.
 * fgets1.c
 * 使用fgets（）和 fputs（）
 * 
 ****************************************************************************/

#include <stdio.h>

#define STLEN 14

int main( void )
{
    char words[STLEN];

    puts("Enter a string, please.");                             // puts() 函数会自动在末尾添加换行符
    fgets(words, STLEN, stdin);                                  // 有目标空间的地址, 读入字符最大数量，和要读入的文件三个参数; 遇到\n或达到最大数量停止，并将\n存储
    printf("Your string twice(puts(), ten fputs()):\n");
    puts(words);
    fputs(words, stdout);                                        // stdin 为标准输入流， stdout 为标准输出流， 在c中作用同文件一样
    puts("Enter another string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice(puts(), ten fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Done.");


    printf("\n\n\n");                                               // 分割一下程序块，下面为另一段程序


    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')  // fgets() 返回一个指针，成功返回的地址与第一个参数相同，失败（错误或读到EOF）返回NULL
        fputs(words, stdout);
    puts("Done.");

    return 0;
    }

