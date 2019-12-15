/****************************************************************************
 * 
 * 11.
 * testfit.c
 * 使用缩短字符串长度的函数
 * 演示strlen（）函数
 * strlen()函数返回字符串长度，不包括\0，如：strlen("hello") == 5;
 * 
 ****************************************************************************/

#include <stdio.h>
#include <string.h>

void fit ( char *, unsigned int );                                              // 由于要改变字符串，所以没有用const限定符

int main( void )
{
    char mesg[] = "Things should be as simple as possible, but not simpler.";

    puts(mesg);
    fit(mesg, 38);
    puts(mesg);
    puts("Let's look at some more of the string.");
    puts(mesg + 39);

    return 0;
}

void fit(char *string, unsigned int size)
{
    if ( strlen(string) > size )
        string[size] = '\0';
}

/* 
 * <string.h> 头文件中其他常用函数：
 * char * strcat( char * str1, char * str2); 函数将第二个字符串拼接到第一个字符串后，返回拼接后第一个字符串的地址，第二个字符串不变。
 * char * strncat( char * buf, char * adden, int n); 函数第三个参数表示允许添加的最大字符数
 * int strcmp( char * str1, char * str2); 函数比较两个字符串的大小，按照机器排序序列进行比较，返回str1-str2; 注意不要将'a'等字符作为其参数
 * int strncmp( char * str1, char * str2, int n); 同strcmp(); 第三个参数用来限定查找的范围，如查找以astro开头的字符串：
 *                      if ( strncmp(list[i], "astro", 5) == 0 ); 函数只比较前五个字符，相等则返回0；
 * char * strcpy(char * str1, char * str2); 函数将第二个字符串拷贝到第一个字符串的位置，返回第一个参数的值；第一个参数不必指向数组开始，可以部分拷贝；
 *                                                      注意第一个参数要提前分配内存且够大，否则会溢出。
 * char * strncpy(char * str1, char * str2, int n); 同strcpy; 第三个参数规定了最大拷贝数量； 注意预留\0的位置。
 * sprintf( char * str, ... ); 同printf()；头文件为<stdio.h>；格式化输出到第一个参数处的字符串中。
 */