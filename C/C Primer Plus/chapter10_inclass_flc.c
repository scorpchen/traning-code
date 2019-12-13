/**********************************************
 * 
 * 10.
 * flc.c
 * 复合字面量
 * 
 ***********************************************/

#include <stdio.h>

#define COLS 4
#define PRINT(X)    printf("total"#X" = %d\n", total##X);               // ‘#’字符串化运算符 和 ‘##’粘合运算符的有趣用法

int sum2d(const int ar[][COLS], int rows);
int sum(const int ar[], int n);

int main(void)
{
    int total1, total2, total3;
    int * pt1;
    int (*pt2)[COLS];

    pt1 = (int [2]) { 12, 20 };                                     // 复合字面量， 同字面量一样存储在静态区，程序开始时分配内存
    pt2 = (int [2][COLS]) { { 1, 2, 3, -9 }, { 4, 5, 6, -8 } };

    total1 = sum(pt1, 2);
    total2 = sum2d(pt2, 2);
    total3 = sum( (int []) { 4, 4, 4, 5, 5, 5 }, 6);
    PRINT(1);
    PRINT(2);
    PRINT(3);

    return 0;
}

int sum(const int ar [], int n)
{
    int i;
    int total = 0;

    for (i = 0; i < n; ++i)
        total += ar[i];
    
    return total;
}

int sum2d(const int ar [][COLS], int rows)
// 也可以写成：
// int sum2d(const int (*ar)[COLS], int rows)
// 意思是一个指向大小为COLS的数组的指针
// 也正是如此才会在传数组参数时指定列的大小
{
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < rows; ++r)
        for (c = 0; c < COLS; ++c)
            tot += ar[r][c];
    
    return tot;
}