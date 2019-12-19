/****************************************************************************
 * 
 * 11.13.15
 * 使用字符分类函数实现atoi()函数。如果输入的字符串不是纯数字，返回0；
 * 
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int atoi1(const char *);

int main( int ac, char *av[] )
{
    char *p[] = {"45apple", "3456", "printf34", "orange"};
    for (int i = 0; i < sizeof(p)/sizeof(char *); ++i){
        printf("%-6d:  %s\n", atoi1(p[i]), p[i]);
    }
    return 0;
}

int atoi1(const char *p)
{
    int i = 0;
    if ( !isdigit(*p) ) return 0;
    while( isdigit(*p) ){
        i = i * 10 + (*p++ - '0');
    }
    return i;
}