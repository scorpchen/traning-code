/****************************************************
*  “最大子列和”被定义为所有连续子列元素的和中最大者。   *
*  例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续    *
*  子列{ 11, -4, 13 }有最大的和20。现要求你编写程序， *
*  计算给定整数序列的最大子列和。                    *
***************************************************/

#include <stdio.h>
#define K 100010

int main(){
    int sum[K] = {0}, num[K] = {0};
    int max = 0;
    int n;
    int flag = 0;

    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &num[i]);
        if(num[i] >= 0 && flag == 0){
            flag = 1;
        }
    }
    if(flag == 0) {
        printf("%d", 0);
        return 0;
    }
    for(int i=1; i<=n; i++){
        sum[i] = (sum[i-1]+num[i] > num[i]) ? (sum[i-1]+num[i]) : num[i];
        max = max>sum[i] ? max: sum[i];
    }
    printf("%d", max);

    return 0;
}
