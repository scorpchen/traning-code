/**********************************************
 * 
 * 8.11.2
 * 编写一个程序，在遇到EOF之前，把输入作为字符流
 * 读取。程序要求报告输入中的大小写个数。
 * 
 ***********************************************/

#include <stdio.h>
#include <ctype.h>

int main(){
    int ch;
    int up_count = 0;
    int low_count = 0;

    while((ch = getchar()) != EOF){
        if(islower(ch)) low_count++;
        else if(isupper(ch)) up_count++;
        else continue;
    }

    printf("The count of upper letter is: %d\n"
           "The count of lower letter is: %d\n",
           up_count, low_count);


    return 0;
}