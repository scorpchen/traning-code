/****************************************************************************
 * 
 * 12.9.8
 * 完成函数
 * 
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * make_array(int elem, int val);
void show_array(const int ar [], int n);

int main( void )
{
    int * pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while ( scanf("%d", &size) == 1 && size > 0 ){
        printf("enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array( size, value );
        if ( pa ){
            show_array( pa, size );
            free(pa);
        }
        printf("Enter the number os elements (<1 to quit): ");
    }
    printf("Done.\n");

    return 0;
}

int * make_array(int elem, int val)
{
    int * p = (int *) malloc( elem * sizeof(int) );
    for (int i = 0; i < elem; ++i ){
        p[i] = val;
    }
    return p;
}

void show_array(const int ar [], int n)
{
    int i;
    for ( i = 0; i < n; ++i ){
        printf("%5d", ar[i]);
        if ( i % 8 == 7 ) printf("\n");
    }
    if ( i % 8 != 0) putchar('\n');
}