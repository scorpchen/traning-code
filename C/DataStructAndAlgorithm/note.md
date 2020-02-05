抽象数据类型：数据对象集、操作集

# 线性表

##　数据对象集：n个元素构成的有序序列
##　操作集：
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