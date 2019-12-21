/**********************************************
 * 
 * 13.
 * reverse.c
 * 
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'                                   // Dos 文本文件中的文件结尾标记
#define SLEN 81

int main( void )
{
    char file[SLEN];
    char ch;
    FILE *fp;
    long count, last;

    puts( "Enter the name of the file to be processed:");
    scanf( "%80s", file );
    if ( (fp = fopen(file, "rb")) == NULL ){
        printf( "revers can't open %s\n", file );
        exit(EXIT_FAILURE);
    }

    fseek( fp, 0L, SEEK_END );                          // 定位到文件末尾
    last = ftell( fp );

    for ( count = 1L; count <= last; ++count ){
        fseek( fp, -count, SEEK_END );
        ch = getc( fp );
        if ( ch != CNTL_Z && ch != '\r' )
            putchar( ch );
    }
    putchar('\n');
    fclose( fp );

    return 0;
}

/* fseek() 
 * 第一个参数为文件指针
 * 第二个参数为偏移量，long型值，可以为正（前移）、负（后移）、0（保持不动）。
 * 第三个参数为模式，确定起始点：SEEK_SET 文件开始、SEEK_CUR 当前位置、SEEK_END 文件末尾。
 * 正常返回0，错误返回-1.
 * 
 * ftell()
 * 以文件指针为参数
 * 返回指向当前指向位置距离文件开始处的字节数，类型为long
 * 适用于以二进制模式打开的文件
 * 
 * 以上两个函数把文件大小限制到了long型大小内，若文件更大，可用下面两个函数：
 * 
 * fgetpos() 和 fsetpos()
 * 这两个函数使用 fpos_t 类型。
 * int fgetpos( FILE * restrict stream, fpos_t * restrict pos );
 * 该函数将当前位置距离文件开始处的字节数放入pos指向的位置，成功返回0，失败返回非0；
 * int fsetpos( FILE * stream, const fpos_t *pos );
 * 该函数将文件指针指向从文件开头偏移*pos值后的位置，成功返回0，失败返回非0；
 */