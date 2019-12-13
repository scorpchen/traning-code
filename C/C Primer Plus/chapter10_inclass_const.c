/**********************************************
 * 
 * 10.
 * const.c
 * 关于const的初始化
 * 
 ***********************************************/

#include <stdio.h>

#define MONTHS 12

int main(void){
    // const int MONTHS = 12;                                   // 和 #define 一样可以创建符号常量, 但这里好像不能用来初始化数组下标
    const int days[MONTHS] = {31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};          // 用const关键字保护数据
    // days[9] = 44;                                            // 若尝试对其赋值，编译器将报错

    double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
    const double *pd = rates;                                   // 可以用一般变量向指向 const 的指针赋值，此时不能通过指针pd修改rates
    // *pd = 34.3;                                              // 编译器报错
    rates[2] = 34.33;                                           // 允许
    ++pd;                                                       // 允许指向const的指针指向别处
    
    // 指向const的指针通常用于函数形参，表示不会通过函数改变数据，如：
    // void show_array(const double *ar, int n);

    int *pc = days;                                             // 按理说来应该不允许const数据赋值非const指针，但是本编译器竟然编译过了
    *pc = 34;                                                   // 但是还是给了一个警告
                                                                // 使用非const标识符修改const数据导致的结果未定义
    
    double * const pb = rates;                                  // 定义不允许指向别处的指针， c++中，叫做顶层const，而上面那种叫做底层const
    // ++pb;                                                    // 报错

    const double * const pa = rates;                            // 既不允许通过pa修改rates的值，也不允许pa指向别处

    return 0;
}
