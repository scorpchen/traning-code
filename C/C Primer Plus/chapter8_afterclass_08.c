/**********************************************
 * 
 * 8.11.2
 * 编写一个程序，显示一个提供加法、减法、乘法和除法
 * 的菜单, 并实现。
 * 
 ***********************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void display_menu( void );
char get_choice();
void get_number(void *, void *, char);
double calc( float, float , char );
void display_result(float a, float b, double r, char);
void exit_code( void ) { printf("Bye!\n");}
char get_op( char );

int main(){
    char choice, operator;
    float calc_num1, calc_num2;
    double result;

    atexit(exit_code);

    while(true){
        display_menu();
        choice = get_choice();
        if( choice == 'q') exit(0);
        get_number(&calc_num1, &calc_num2, get_op(choice));
        result = calc(calc_num1, calc_num2, choice);
        display_result(calc_num1, calc_num2, result, get_op(choice));
    }


    return 0;
}

void display_menu( void ){
    fprintf(stdout, "Enter the operation of your choice:\n"
                    "a. add             s. subtract\n"
                    "m. multiply        d. divide\n"
                    "q. quit\n"
                    );
}

char get_choice(){
    char ch;
    while( (ch = getchar()) != EOF )
        if( ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q'){
            printf("'%c' is not a good choice, please choose one operation from the follow:\n", ch);
            continue;
        }
        else {
            getchar();
            return ch;
        }
    if(ch == EOF) exit(0);
}

void get_number(void *a, void *b, char op){
    char ch;
    float num = 0;
    double i = 1;
    bool integer = true;
    bool digit = false;
    while(!digit){
        printf("Enter first number:    ");
        while((ch = getchar()) != '\n'){
            if(!isdigit(ch) && ch != '.') continue;
            else {
                digit = true;
                if(isdigit(ch) && integer){
                    num = num*10 + ch-'0';
                }
                else if(ch == '.') integer = false;
                else if(isdigit(ch) && !integer){
                    num = num + pow(10, -i)*(ch - '0');
                    ++i;
                }
            }
        }
        if(!digit) printf("Please enter a number!\n");
    }
    float *p = a;
    *p = num;

    
    num = 0;
    i = 1;
    integer = true;
    digit = false;
    if(op != '/'){
        while(!digit){
            printf("Enter second number:    ");
            while((ch = getchar()) != '\n'){
                if(!isdigit(ch) && ch != '.') continue;
                else {
                    digit = true;
                    if(isdigit(ch) && integer){
                        num = num*10 + ch-'0';
                    }
                    else if(ch == '.') integer = false;
                    else if(isdigit(ch) && !integer){
                        num = num + pow(10, -i)*(ch - '0');
                        ++i;
                    }
                }
        }
        if(!digit) printf("Please enter a number!\n");
    }
    }
    else{
        while( !num ){
            while(!digit){
                printf("Enter second number:    ");
                while((ch = getchar()) != '\n'){
                    if(!isdigit(ch) && ch != '.') continue;
                    else {
                        digit = true;
                        if(isdigit(ch) && integer){
                        num = num*10 + ch-'0';
                        }
                        else if(ch == '.') integer = false;
                        else if(isdigit(ch) && !integer){
                        num = num + pow(10, -i)*(ch - '0');
                        ++i;
                        }
                    }
                }
                if(!digit) printf("Please enter a number!\n");
            }
            if(num == 0) {
                printf("Can divide a number by 0!\n");
                digit = false;
            }
        }
    }
    p = b;
    *p = num;
}

double calc( float a, float b, char ch ){
    double result;

    if(ch != 'a' &&  ch != 's' && ch != 'm' && ch != 'd'){
        printf("Calc error!");
        exit(1);
    }
    else{
        switch (ch){
            case 'a': return result = a + b; break;
            case 's': return result = a - b; break;
            case 'm': return result = a * b; break;
            case 'd': return result = a / b; break;
            default : printf("Calc error!"); exit(1);
        }
    }
}

void display_result(float a, float b, double r, char op){
    printf("%g %c %g = %g\n", a, op, b, r);
}

char get_op( char ch ){
    switch (ch){
            case 'a': return '+'; break;
            case 's': return '-'; break;
            case 'm': return '*'; break;
            case 'd': return '/'; break;
            default : exit(1);
        }
}