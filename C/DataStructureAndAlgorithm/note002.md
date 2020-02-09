# 查找
根据给定的某个关键词K，从集合R中找出关键字与K相同的记录

## 静态查找：集合中的记录是固定的
* 没有插入和删除操作，只有查找

### 顺序查找
```
struct LNode{
    ElementType Element[MAXSIZE];
    int Length;
}
typedef struct LNode *List;

//无“哨兵”
int SequentialSearch (List Tb1, ElementType K)
{
    int i;
    for( i = Tb1->Length; i>0 && Tb1->Element[i]!=K; --i );
    return i;
}

// 有“哨兵”
int SequentialSerch (List Tb1, ElementType K)
{
    int i;
    Tb1->Element[0] = K;
    for( i = Tb1->Length; Tb1->Element[i] != K; --i );
    return i;   //成功返回下标，不成功返回0；
}
```

### 二分查找（Binary Search)
```
int BinarySearch( List Tb1, ElementType K )
{
    int left, right, mid, NoFound=-1;

    left = 1;
    right = Tb1->Length;
    while( left <= right ){
        mid = (left + right)/2;
        if ( K < Tb1->Element[mid] )
            right = mid - 1;
        else if( K > Tb1->Element[mid] )
            left = mid + 1;
        else 
            return mid;
    }
    return NotFound;
}
```
二分查找判定树

## 动态查找；集合中的记录是变化的
* 除了查找外，还有插入和删除



# 树(Tree)
1. 结点的度（Degree）：结点的子树个数
2. 树的度：树的所有结点中最大的度数
3. 叶节点（Leaf）：度为零的结点
4. 父结点（Parent）：有子树的结点是其子树的根结点的父结点
5. 子结点（Child）
6. 兄弟结点（Sibling）：具有同一父结点的各结点
7. 路径
8. 路径长度
9. 祖先结点（Ancestor）
10. 子孙结点（Descendant）
11. 结点层次（Level）：根节点在第一层
12. 树的深度（Depth）：树中所有结点中的最大层次是这棵树的深度

## 树的表示
* 儿子-兄弟表示法

### 二叉树
可以为空，左子树和右子树
* 斜二叉树
* 完美二叉树（Perfect Binary Tree）、满二叉树（Full Binary Tree
* 完全二叉树（Complete Binary Tree）

#### 性质
* 一个二叉树第i层的最大结点数为： 2^(i-1)
* 深度为k的二叉树有最大结点数为：2^k-1
* 对任何非空二叉树T，叶节点个数等于度为二的非叶节点个数加一

### 操作集：
1. Boolean IsEmpty( BinTree BT ): 判断BT是否为空
2. void Traversal( BinTree BT ): 遍历
3. BinTree CreatBinTree(): 创建二叉树
```
// 先序遍历
void PreOrderTraversal( BinTree BT )
// 中序遍历
void InOrderTraversal( BinTree BT )
// 后序遍历
void PostOrderTraversal( BinTree BT )
// 层次遍历
void LevelOrderTraversal( BinTree BT )
```

```
// 顺序存储结构
// 完全二叉树，非完全二叉树可以填充成完全二叉树（但会造成空间浪费）

// 链表存储
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
}

// 二叉树的遍历
// 先序遍历:先根，再左，后右
Void PreOrderTraversal( BinTree BT )
{
    if( BT ){
        printf( "%d", BT->Data );
        PreOrderTraversal( BT->Left );
        PreOrderTraversal( BT->Right );
    }
}
// 中序遍历：先左，再根，再右
Void PreOrderTraversal( BinTree BT )
{
    if( BT ){
        PreOrderTraversal( BT->Left );
        printf( "%d", BT->Data );
        PreOrderTraversal( BT->Right );
    }
}
// 后序遍历：先左，再右，再根
Void PreOrderTraversal( BinTree BT )
{
    if( BT ){
        PreOrderTraversal( BT->Left );
        PreOrderTraversal( BT->Right );
        printf( "%d", BT->Data );
    }
}

// 非递归遍历
// 基本思路：使用堆栈
void InOrderTraversal( BinTree BT )
{
    BinTree T = BT;
    Stack S = CreatStack( MaxSize );
    while( T || !IsEmpty(S) ){
        while(T){
            Push(S, T);
            T = T->Left;
        }
        if( !IsEmpty(S) ){
            T = Pop(S);
            printf("%5d", T->Data); // 将该行换到向前第五行Push（）处便是先序遍历
            T = T->Right;
        }
    }
}

// 层序遍历
// 二叉树遍历的核心问题：二维结构的线性化
// 队列实现
void LevelOrderTraversal( BinTree BT )
{
    Queue Q;
    BinTree T;
    if ( !BT ) return;
    Q = CreatQueue( MaxSize );
    AddQ( Q, BT );
    while ( !IsEmptyQ(Q) ){
        T = DeleteQ( Q );
        printf("%d/n", T->Data);
        if ( T->Left ) AddQ( Q, T->Left );
        if ( T->Right ) AddQ( Q, t->Right );
    }
}

// 遍历二叉树的应用：输出叶子结点
void PreOrderPrintLeaves( BinTree BT )
{
    if ( BT ){
        if( !BT->Left && !BT->Right )
            printf( "%d", BT->Data );
        PreOrderPrintLeaves( BT->Left );
        PreOrderPrintLeaves( BT->Right );
    }
}

// 求二叉树的高度：Height = max(H_L, H_R)+1
int PostOrderGetHeight( BinTree BT )
{
    int HL, HR, MaxH;
    if( BT ){
        HL = PostOrderGetHeight( BT->Left );
        HR = PostOrderGetHeight( BT->Right );
        MaxH = (HL > HR) ? HL : HR;
        return ( MaxH + 1 );
    }
    else return 0;
}
```

```

```