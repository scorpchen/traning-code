/****************************************************************************
 * 
 * 11.13.16
 * 编写一个程序读取输入，直至读到文件结尾，然后把字符串打印出来。该程序识别和实现
 * 下面的命令行参数：
 *      -p  按照原样打印
 *      -u  把输入全部转换成大写
 *      -l  把输入全部转换成小写
 * 若没有命令行参数，则同-p
 * 
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main( int ac, char *av[] )
{
    enum {p, u, l} mod;
    FILE *fp;
    if (ac == 2){
        switch (av[1][1]){
            case 'p':   mod = p; break;
            case 'u':   mod = u; break;
            case 'l':   mod = l; break;
            default:    mod = p; break;
        }
        fp = stdin;
    }
    else if (ac == 3){
        switch (av[2][1]){
            case 'p':   mod = p; break;
            case 'u':   mod = u; break;
            case 'l':   mod = l; break;
            default:    mod = p; break;
        }
        fp = fopen(av[1], "r");
    }
    else {
        mod = p;
        fp = stdin;
    }

    char ch[81] = {0};
    while ( fgets(ch, 81, fp) ){
        switch (mod){
            case p:     fputs(ch, stdout); break;
            case u:     {int i=0;
                        while ( ch[i] != '\0' ) putchar(toupper(ch[i++]));
                        break;}
            case l:     {int i=0;
                        while ( ch[i] != '\0' ) putchar(tolower(ch[i++]));
                        break;}
        }
    }

    if (ac == 3) fclose(fp);

    return 0;
}
