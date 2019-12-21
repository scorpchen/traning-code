/**********************************************
 * 
 * 13.
 * count.c
 * 
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>                                                     // exit() 函数原型在<stdlib.h>头文件中

int main( int argc, char *argv [] )
{
    int ch;
    FILE *fp;
    unsigned long count = 0;
    if ( argc != 2 ){
        printf( "Usage: %s filename\n", argv[0] );
        exit( EXIT_FAILURE );
    }
    if ( (fp = fopen( argv[1], "r" )) == NULL ){
        printf( "Can't open %s\n", argv[1] );
        exit( EXIT_FAILURE );
    }
    while ( (ch = getc(fp)) != EOF ){
        putc( ch, stdout );
        ++count;
    }
    fclose( fp );
    printf( "\nFile %s has %lu characters\n", argv[1], count );

    return 0;
}


/* 
 * c 会自动打开3个文件， 标准输入：stdin， 标准输出：stdout， 标准错误：stderr。
 * 
 */