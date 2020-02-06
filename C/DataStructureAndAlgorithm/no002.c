/*************************************************
 * 
 * 多项式的和与乘积
 * 
 * ***********************************************/

#include <stdio.h>
#include <stdlib.h>

struct PolyNode{
    int coef; // 系数
    int expon; // 指数
    struct PolyNode *link;
};
typedef struct PolyNode *Polynomial;

Polynomial ReadPoly();
Polynomial PolyAdd( Polynomial P1, Polynomial P2);
Polynomial PolyMult( Polynomial P1, Polynomial P2 );
void Attach(int c, int e, Polynomial *pRear);
void PrintPoly( Polynomial P );
int Compare( int a, int b )
{
    if ( a == b ) return 0;
    return a>b?1:-1;
}

int main( void )
{
    Polynomial P1, P2, PP, PS;

    // 读入多项式1
    P1 = ReadPoly();
    
    // 读入多项式2
    P2 = ReadPoly();
    
    // 乘法运算并输出
    PP = PolyMult( P1, P2 );
    PrintPoly( PP );
    
    // 加法运算并输出
    PS = PolyAdd( P1, P2 );
    PrintPoly( PS );

    return 0;
}

Polynomial ReadPoly()
{
    int N;
    int e, c;
    Polynomial Rear, P, temp;

    scanf("%d", &N);
    P = (Polynomial)malloc( sizeof(struct PolyNode) );
    P->link = NULL;
    Rear = P;
    while(N--){
        scanf("%d %d", &c, &e);
        Attach(c, e, &Rear);
    }
    temp = P; P = P->link; free(temp);
    return P;
}


Polynomial PolyAdd( Polynomial P1, Polynomial P2)
{
    Polynomial front, rear, temp, P;
    int sum;
    rear = (Polynomial) malloc( sizeof(struct PolyNode));
    front = rear;       // front记录结果多项式链表头节点
    while( P1 && P2 )
        switch( Compare(P1->expon, P2->expon) ){
            case 1:
                Attach( P1->coef, P1->expon, &rear );
                P1 = P1->link;
                break;
            case -1:
                Attach(P2->coef, P2->expon, &rear);
                P2 = P2->link;
                break;
            case 0:
                sum = P1->coef + P2->coef;
                if(sum) Attach(sum, P1->expon, &rear);
                P1 = P1->link;
                P2 = P2->link;
                break;
        }
    for( ; P1; P1 = P1->link) Attach(P1->coef, P1->expon, &rear);
    for( ; P2; P2 = P2->link) Attach(P2->coef, P2->expon, &rear);
    rear->link = NULL;
    temp = front;
    front = front->link; // 令front指向结果多项式第一个非零项
    free(temp); // 释放头节点

    P = front;

    return P;
}

Polynomial PolyMult( Polynomial P1, Polynomial P2 )
{
    Polynomial P, Rear, t1, t2, t;
    int c, e;

    if ( !P1 || !P2) return NULL;

    t1 = P1; t2 = P2;
    P = (Polynomial)malloc( sizeof(struct PolyNode) );
    P->link = NULL;
    Rear = P;

    while (t2){
        Attach( t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while (t1){
        t2 = P2;
        Rear = P;
        while (t2){
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            while ( Rear->link && Rear->link->expon > e )
                Rear = Rear->link;
            if ( Rear->link && Rear->link->expon == e ){
                if ( Rear->link->coef + c)
                    Rear->link->coef += c;
                else{
                    t = Rear->link;
                    Rear->link = t->link;
                    free( t );
                }
            }
            else{
                t = (Polynomial)malloc( sizeof(struct PolyNode) );
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t2 = P;
    P = P->link;
    free(t2);

    return P;
}

void Attach(int c, int e, Polynomial *pRear)
{
    Polynomial P;

    P = (Polynomial)malloc( sizeof(struct PolyNode) );
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;
}

void PrintPoly( Polynomial P )
{
    int flag = 0;

    if ( !P ){
        printf("0 0\n");
        return ;
    }

    while ( P ){
        if ( !flag )
            flag = 1;
        else
        {
            printf(" ");
        }
        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}

