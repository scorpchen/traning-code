/**********************************************
 * 
 * 12.
 * type qualifiers.c
 * 类型限定符
 * 
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 类型限定符等幂（c99）
    const const const int n = 6;        // 同 const int n = 6;
    // 由此属性可以编写如下代码：
    typedef const int zip;
    const zip q = 8;


    // volatile 限定符表示易变量，可能被其他程序修改，因此每次都需要从原位置读取而不能在缓存中读取
    volatile int loc1;


    // volatile 可以和 const 一起用，表示可以被其他程序修改而不能被本程序修改，二者顺序不重要
    volatile const int loc;
    const volatile int * ploc;


    // restrict 关键字用于指针，表示该指针是访问数据对象唯一且初始的方式，用于编译器优化


    // _Atomic 类型限定符表示原子类型，一次只能被一个线程修改，在可选的头文件 <stdatomic.h> 和 <threads.h> 中定义


    // c99 允许把类型限定符放在函数原型和函数头的形式参数的初始化方括号中：
    void ofmouth(int * const a1, int * restrict a2, int n);     // 以前的风格
    void ofmouth(int a1[const], int a2[restrict], int n);       // c99 新风格


    // 对于存储类型说明符 static，c99 引入了一种新用法：
    double stick( double ar[static 20] );           // 此用法表明参数为指向数组首元素的指针，且数组至少有20个元素


    return 0;
}