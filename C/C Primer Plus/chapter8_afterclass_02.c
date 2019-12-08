/**********************************************
 * 
 * 8.11.2
 * 编写一个程序，在遇到EOF之前，把输入作为字符流
 * 读取。程序要打印每个输入的字符及其相应的ASCII
 * 十进制值。
 * 
 ***********************************************/

#include <stdio.h>

int main(){
    int ch;
    int count = 0;
    while((ch = getchar()) != EOF){
        if(ch >= 32){
            putchar(ch);
            printf(": %d ", ch);
            count++;
        }
        else if(ch == '\n'){
            putchar('\n');
            count = 0;
        }
        else if(ch == '\t') putchar('\t');
        else {
            putchar('^');
            putchar(ch+64);
            printf(": %d ", ch);
            count++;
        }
        if(count%10 == 0) printf("\n");
    }


    return 0;
}