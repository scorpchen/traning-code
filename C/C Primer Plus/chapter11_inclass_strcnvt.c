/****************************************************************************
 * 
 * 11.
 * strcnvt.c
 * 使用strtol()
 * 
 * long strtol (const char * restrict nptr, char ** restrict endptr, int base);
 * nptr为指向带转换字符的指针
 * endptr是一个指针的地址，该指针会被设置为标识输入数字结束字符的地址
 * base表示以什么进制进行转换，即将带转换字符看成什么进制，最大为36，a-z都可以作为
 * 数字。
 * restrict 限定符用于指针，表示其是访问数据对象唯一且初始的方式，表示其指向的数据
 * 不会在其他位置改变。
 * 
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>                                                             // strtol() 在<stdlib.h>头文件

#define LIM 30

char * s_gets(char * st, int n);

int main( void )
{
    char number[LIM];
    char * end;
    long value;

    puts("Enter a number (empty line to quit):");
    while ( s_gets(number, LIM) && number[0] != '\0'){                            // 读到空行或者文件结尾结束
        value = strtol(number, &end, 10);
        printf("base 10 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);
        value = strtol(number, &end, 16);
        printf("base 16 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);
        puts("Next number: ");
    }
    puts("Bye!\n");

    return 0;
}

char * s_gets(char *st, int n)
/* 
 * 此函数读取一行，若目标位置够大，则将存入一行并丢弃换行符
 * 若目标位置不够大，则丢弃剩下的字符
 */
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if ( ret_val ){
        while ( st[i] != '\n' && st[i] != '\0' )
            i++;
        if ( st[i] == '\n' )
            st[i] = '\0';
        else
            while ( getchar() != '\n')
                continue;
    }
    return ret_val;
}

/* 
 * <stdlib.h>中其他字符串转数字函数：
 * int atoi( char * ); 函数将字符串转换为整数，若仅以数字开头，则将数字部分转换为整数，若没有数字，则返回未定义。
 * double atof( char * );
 * long atol( char * );
 * 
 * unsigned long strtoul(const char * restrict nptr, char ** restrict endptr, int base); 同strtol;
 * double strtod(const char * restrict nptr, char ** restrict endptr); 注意只有两个参数，只能以十进制转换
 */