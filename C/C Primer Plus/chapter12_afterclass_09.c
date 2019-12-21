/****************************************************************************
 * 
 * 12.9.9
 * 编写一个函数，要求：
 * 询问用户需要输入多少单词，然后接收用户输入的单词并显示，使用malloc()函数；
 * 创建一个动态数组，该数组内含指向char的指针，每个指针指向一个字符串对象；
 * 每个字符串对象大小正好能容纳被存储的特定单词。
 * 
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( void )
{
    int num;
    fputs("How many words do you wish to enter?      ", stdout);
    while ( scanf("%d", &num) != 1){
        fputs("You must enter a integer. Please try again:       ", stdout);
    } 

    char * pwords1[num];                                                        // 变长数组
    char ** pwords2 = (char **) malloc( num * sizeof(char *) );                 // 使用malloc()函数构建变长数组

    puts("Enter 5 words now:");
    char ch_temp[81];
    size_t size;
    for ( int i = 0; i < num; ++i ){
        scanf("%s", ch_temp);
        size = strlen(ch_temp);
        pwords1[i] = (char *) malloc( (size+1) * sizeof(char) );
        pwords2[i] = (char *) malloc( (size+1) * sizeof(char) );
        strncpy( pwords1[i], ch_temp, size+1 );
        strncpy( pwords2[i], ch_temp, size+1 );
    }

    puts("Here are your words:");
    for ( int i = 0; i < num; ++i ){
        puts(pwords1[i]);
        puts(pwords2[i]);
        puts("");
        free(pwords1[i]);
        free(pwords2[i]);
    } 
    free(pwords2);

    return 0;
}
