/**********************************************
 * 
 * 8.11.2
 * 编写一个程序，在遇到EOF之前，把输入作为字符流
 * 读取。程序要求报告输入中平均每个单词的字母数。
 * 
 ***********************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
    int ch;
    int letter_count = 0;
    int letter_num = 0;
    int sum = 0;
    bool first_blank = true;

    while( (ch = getchar()) != EOF ){
        if( !isalpha(ch) && !letter_count && !letter_num ) continue;
        
        if( isalpha(ch) ){
            ++letter_count;
            if( !first_blank ) first_blank = true;
        }
        else {
            if(first_blank) {
                first_blank = false;
                ++letter_num;
            }
            else continue;
        }
    }

    printf("%.0lf", (double)letter_count/letter_num);


    return 0;
}