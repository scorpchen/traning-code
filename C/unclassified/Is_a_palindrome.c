#include <stdio.h>
#define STRING_LEN 50
#define VERSION
#ifdef VERSION

void gets_string(char* string);

int main(){
    int idex = 0;
    char string[STRING_LEN];

    while(1){
        int num = 0;
        int flag = 0;
        printf("%s", "Enter a message: ");
        gets_string(string);
        if(string[0] == 'q' && string[1] == '\0') break;
        for(num=0; string[num]!='\0'; num++);
        for(int i=0; i<num/2; i++){
            if(string[i]!=string[num-1-i]){
                printf("Not a palindrome\n");
                flag = 1;
                break;
            }
        }
        if(flag == 0) printf("Palindrome\n");
        printf("%s\n", string);
    }
    

    return 0;
}

void gets_string(char* string){
    char c;
    int i = 0;
    char strings[50];
    while((c = getchar()) != '\n'){
        if(c >= 'A' && c <= 'Z') c -= ('A'-'a');
        if(c >= 'a' && c <= 'z'){
            strings[i] = c; 
            string[i] = c;
            i++;
        }  
    }
    string[i] = '\0';
}


#endif
