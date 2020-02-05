// 对比两个实现：
#include <time.h>
#include <stdio.h>
void PrintN1(int N)
{
    int i;
    for (i=1; i<=N; i++){
        printf("%d\n", i);
    }
}

void PrintN2(int N)
{
    if(N){
        PrintN2(N-1);
        printf("%d\n", N);
    }
}

int main()
{
    int n;
    clock_t start, finish;
    printf("%d", CLK_TCK);

    getchar();
    
    while(1){
        scanf("%d", &n);
        if(n < 0) break;

        printf("case 1:     ");
        start = clock();
        PrintN1(n);
        finish = clock();
        printf("%lf \n", (double)(finish-start)/CLK_TCK);

        getchar();

        printf("case 2:     ");
        start = clock();
        PrintN2(n);
        finish = clock();
        printf("%lf \n", (double)(finish-start)/CLK_TCK);

    }

    return 0;
}