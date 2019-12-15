/**********************************************
 * 
 * 11.
 * arrchar.c
 * 比较指针和数组的存储方式
 * 
 ***********************************************/

#include <stdio.h>

#define SLEN 40
#define LIM 5

int main( void )
{
    const char *mytalents[LIM] = {
        "Adding numbers swiftly",
        "Multiplying accurately",
        "Stashing data",
        "Following instructions to the letter",
        "Understanding the C language"
    };
    char yourtalents[LIM][SLEN] = {
        "Walking in a straight line", 
        "Sleeping",
        "watching television",
        "Mailing letters",
        "Reading email"
    };

    int i;

    puts("Let's compare talents.");
    printf("%-36s %-25s\n", "My Talents", "Your Talents");
    for (i = 0; i < LIM; ++i)
        printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);
    printf("\nsizeof mytalents: %zd， sizeof yourtalents: %zd\n", sizeof(mytalents), sizeof(yourtalents));
                                       // %zd 表示 size_t 类型的值。其他类似的还有 %td ，表示ptrdiff_t 类型的值，是两个指针之差的类型（c99）

    return 0;
    }

/* 
 * 程序结果说明了指针和数组的差别，指针指向了静态储存空间中的字面量，
 * 而数组将其拷贝了一份。
 */