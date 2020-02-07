
抽象数据类型：数据对象集、操作集


# 线性表

## 数据对象集：n个元素构成的有序序列

## 操作集：
List MakeEmpty()：初始化一个空线性表L；
ElementType FindKth(int K, List L): 根据位序K，返回相应元素；
int Find(ElementType X, List L)：在线性表L中查找X的第一次出现位置；
void Insert（ElementType X, int i, List L)：在位序i前插入新元素X；
void Delete(int i, List L): 删除指定位序i处的元素
int Length(List L)：返回线性表的长度

## 顺序存储实现：
利用数组的连续存储空间顺序存放线性表元素
```
typedef struct LNode* List;
struct LNode{
    ElementType Data[MAXSIZE];
    int Last;
};
struct LNode L;
List PtrL;
```
访问下标为i的元素：L.Data[i]或PtrL->Data[i]
线性表的长度：L.Last+1或PtrL->Last+1

### 主要操作的实现：

```
//初始化
List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc( sizeof(struct LNode) );
    Ptrl->Last = -1;
    return Ptrl;
}

//查找
int Find(ElementType X, List PtrL)
{
    int i = 0;
    while(i <= PtrL->Last && PtrL->Data[i] != X)
        ++i;
    if(i > PtrL->Last) return -1; // 没找到返回-1
    else return i;
}

//插入：先移动再插入
void Insert(ElementType X, int i, List PtrL)
{
    int j;
    if(PtrL->Last == MAXSIZE-1){
        printf("表空间已满");
        return;
    }
    if(i<1 || i>PtrL->Last+2){
        printf("位置不合法");
        return;
    }
    for(j = PtrL->Last; j>=i-1; j--)
        PtrL->Data[j+1] = PtrL->Data[j];
    PtrL->Data[i-1] = X;
    PtrL->Last++;
    return;
}

//删除
void Delete(int i, List PtrL)
{
    int j;
    if(i<1 || i>PtrL->Last+1){
        printf("不存在第%d个元素", i);
        return;
    }
    for(j=i; j<=PtrL->Last; j++)
        PtrL->Data[j-1] = PtrL->Data[j];
    PtrL->Last--;
    return;
}
```

## 链式存储实现：
不要求逻辑上相邻的两个元素物理上也相邻；
通过“链”建立数据元素之间的逻辑关系；
插入、删除不需要移动数据单元，只需修改链
```
typedef struct LNode *List;
struct LNode{
    ElementType Data;
    List Next;
};
struct LNode L;
List PtrL;

//求表长
int Length(List PtrL)
{
    List p = PtrL;
    int j = 0;
    while(p){
        p = p->Next;
        j++;
    }
    return j;
}

//查找
//按照序号查找：

```


```
// 查找:
// 按序号查找：
List FindKth(int K, List PtrL)
{
    List p = PtrL;
    int i = 1;
    while(p != NULL && i < K){
        p = p->Next;
        i++;
    }
    if(i == K) return p;
    else return NULL;
}
// 按值查找
List Find(ElementType X, List PtrL)
{
    List p = PtrL;
    while(p != NULL && p->Data != X)
        p = p->Next;
}

// 插入:
List Insert(ElementType X, int i, List PtrL)
{
    List p,s;
    if(i == 1){
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = PtrL;
        return s;
    }
    P = FindKth(i-1,PtrL);
    if(p == NULL){
        printf("参数错误");
        return NULL;
    }
    else{
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return PtrL;
    }
}

// 删除
List Insert(int i, List PtrL)
{
    List p,s;
    if(i == 1){
        s = PtrL;
        if(PtrL != NULL) PtrL = PtrL->Next;
        else return NULL;
        free(s);
        return PtrL;
    }
    P = FindKth(i-1,PtrL);
    if(p == NULL){
        printf("第%d个结点不存在", i-1); return NULL;
    }
    else if(p->Next == NULL){
        printf("第%d个结点不存在", i); return NULL;
    }
    else{
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return PtrL;
    }
}

```

### 广义表
广义表是线性表的推广
线性表中元素为单元素，广义表中的元素可以是另一个广义表
#### 多重链表
数据：行（row）、列（col）、数值（data/value）

### 堆栈（stack）：具有一定操作约束的线性表
只在一端（栈顶，top）做插入，删除
操作集：
1. Stack CreateStack(int MaxSize): 生成空堆栈，其最大长度为MaxSize
2. int IsFull(Stack S, int MaxSize): 判断堆栈S是否已满
3. void Push(Stack S, ElementType item): 将元素item压入堆栈
4. int IsEmpty(Stack S): 判断堆栈S是否为空
5. ElementType Pop(Stack S): 删除并返回栈顶元素

```
// 栈的顺序存储实现：
#define MaxSize
typedef struct SNode *Stack;
struct SNode{
    ElementType Data[MaxSize];
    int Top;
}

// 入栈：
void Push(Stack PtrS, ElementType item)
{
    if(PtrS->Top == MaxSize-1){
        printf("堆栈满"); return;
    }
    else{
        PtrS->data[++(PtrS->Top)] = item;
        return;
    }
}

// 出栈
ElementType Pop(Stack PtrS)
{
    if(PtrS->Top == -1){
        printf("堆栈空");
        return ERROR;       // ERROR是ElementType的特殊值，标志错误
    }
    else
        return (PtrS->Data[(PtrS->Top)--]);  
}

// 一个数组实现两个堆栈:(最大限度利用空间)
#define MaxSize
struct DStack{
    ElementType Data[MaxSize];
    int Top1;
    int Top2;
} S;
S.Top1 = -1;
S.Top2 = MaxSize;

// 入栈：
void Push( struct DStack *PtrS, ElementType item, int Tag)
{// Tag 作为区分两个堆栈的标志，取值为1和2
    if(PtrS->Top2 - PtrS->Top1 == 1){
        printf("堆栈满"); return;
    }
    if(Tag == 1)
        PtrS->Data[++(PtrS->Top1)] = item;
    else
        PtrS->Data[--(PtrS->Top2)] = item;
}

// 出栈：
ElementType Pop(struct DAtack *PtrS, int Tag)
{
    if(Tag == 1){
        if(PtrS->Top == -1){
            printf("堆栈1空");
            return NULL;
        }
        else return PtrS->Data[(PtrS->Top1)--];
    }
    else{
        if(PtrS->Top2 == Maxsize){
            printf("堆栈2空"); return NULL;
        }
        else return (PtrS->Data[(PtrS->Top)--]);  
}


// 堆栈的链式存储实现
typedef struct SNode *Stack;
struct SNode{
    ElementType Data;
    struct SNode *Next;
};

// 初始化
stack CreateStack()
{// 头节点不代表任何元素
    Stack s;
    s = (Stack)malloc(sizeof(struct SNode));
    s->Next = NULL;
    return s;
}

// 判断是否空栈
int IsEmpty(Stack S)
{ //空栈返回1， 否则返回0
    return （S->Next == NULL）
}

// 入栈
void Push(ElementType item, Stack S)
{
    struct SNode *TmpCell;
    TmpCell = (struct SNode *)malloc(sizeof(struct SNode));
    TmpCell->Element = item;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

// 出栈
ElementType Pop(stack S)
{
    struct SNode *FirstCell;
    ElementType TopElem;
    if(IsEmpty(S)){
        printf("堆栈空"); return NULL;
    }
    else {
        FirstCell = s->Next;
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Element;
        free(FirstCell);
        return TopElem;
    }
}

```
堆栈应用：
中缀表达式转换为后缀表达式：
1. 从头到尾读取每个对象
2. 运算数：直接输出
3. 左括号：压入堆栈
4. 右括号：将栈顶的运算符弹出并输出，直到遇到左括号（出栈，不输出）
5. 运算符：
    1. 若优先级大于栈顶运算符，压入栈
    2. 若优先级小于栈顶运算符，将栈顶运算符弹出并输出，直到栈顶运算符优先级小于该运算符为止，然后压入该运算符
6. 若各对象处理完毕，则输出存留运算符

### 队列：具有一定操作约束的线性表
一端插入，另一端删除
操作集：
1. Queue CreatQueue( int Maxsize ): 生成长度为MaxSize的空队列；
2. int IsfullQ( Queue Q, int MaxSize ); 判断队列Q是否已满
3. void AddQ( Queue Q, ElementType item ); 插入元素
4. int IsEmptyQ( Queue Q ); 判断队列是否为空
5. ElementType DeleteQ( Queue Q ); 读取并删除头元素

```
// 队列的顺序存储实现
#define MaxSize
struct QNode{
    ElementType Data[MaxSize];
    int rear;
    int front;
};
typedef struct QNode *Queue;

// 入队列
void AddQ(Queue PtrQ, ElementType item)
{
    if((PtrQ->rear+1)%MaxSize == PtrQ->front){
        printf("队列满");
        return;
    }
    PtrQ->rear = (PtrQ->rear+1)%MaxSize;
    PtrQ->Data[PtrQ->rear] = item;
}

// 出队列
ElementType DeleteQ(Queue PtrQ)
{
    if(PtrQ->front == PtrQ->rear){
        printf("队列空");
        return ERROR;
    }
    else{
        PtrQ->front = (PtrQ->front+1)%MaxSize;
        return PtrQ->Data[PtrQ->front];
    }
}

// 队列的链式存储实现
struct Node{
    ElementType Data;
    struct Node *Next;
};
struct QNode{
    struct Node *rear;
    struct Node *front;
};
typedef struct QNode *Queue;
Queue PtrQ;

// 出队
ElementType DeleteQ(Queue PtrQ)
{
    struct Node *FrontCell;
    ElementType FrontElem;

    if (PtrQ->front == NULL){
        printf("队列空"); return ERROR;
    }
    FrontCell = PtrQ->front;
    if(PtrQ->front == PtrQ->rear) // 若队列只有一个元素
        PtrQ->front = PtrQ->rear = NULL; // 删除后队列置为空
    else
        PtrQ->front = PtrQ->front->Next;
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}


```
