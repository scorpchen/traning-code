/**********************************************
 * 
 * 12.
 * dyn_arr.c
 * 动态分配数组
 * 
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    double * ptd;
    int max;
    int number;
    int i = 0;

    // 获取数组大小
    puts("What is the maximum number of type double entries?");
    if ( scanf("%d", &max) != 1 ){
        puts("Number not correctly entered -- bye.");
        exit(EXIT_FAILURE);
    }

    // 分配内存空间
    ptd = (double *) malloc(max * sizeof(double));
    if ( ptd == NULL ){
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }
    // ptd 现在指向有max个元素的数组


    puts("Enter the values (q to quit):");
    while ( i < max && scanf("%lf", &ptd[i]) == 1) ++i;
    printf("Here are your %d entries: \n", number = i);
    for ( i = 0; i < number; ++i ){
        printf("%7.2f ", ptd[i]);
        if ( i % 7 == 6) putchar('\n');
    }
    if ( i % 7 != 0) putchar('\n');
    puts("Done.");

    // 释放内存
    free(ptd);

    return 0;
    }


void vla()
/* 
 * 本函数展示用malloc()函数创建二维变长数组，在
 * 不支持变长数组的编译器中只能固定二维数组的维度
 */
{
    int n = 5;
    int m = 6;
    int ar2[n][m];  // n*m 的变长数组
    int (* p2)[6];  // c99 之前的写法
    int (* p3)[m];  // 要求支持变长数组
    p2 = ( int (*)[6] ) malloc( n * 6 * sizeof(int) );  // n*6 数组
    p3 = ( int (*)[m] ) malloc( n * m * sizeof(int) );  // n*m 数组（要求支持变长数组）
    ar2[1][2] = p2[1][2] = 12;                                                                                          
}







/* 
 * 分配内存还可以使用 calloc() 函数：
 * long * newmem;
 * newmen = (long *)calloc( 100, sizeof(long) );
 * calloc() 函数会把内存块所有位置置零；
 */