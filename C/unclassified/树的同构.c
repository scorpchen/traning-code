#include<stdio.h>
#include <string.h>

#define MYVERSION
#ifdef MYVERSION

typedef struct{
    int node;
    char child[11][4];
} tree;

int main(){
    tree tree[2];

    for(int i=0; i<=1; i++){
        scanf("%d", &tree[i].node);
        getchar();
        for(int j=0; j<tree[i].node; j++){
            for(int k=0; k<3; k++){
                scanf("%c", &tree[i].child[j][k]);
                getchar();
            }
            if(tree[i].child[j][1] != '-' && tree[i].child[j][2] != '-') tree[i].child[j][3] = 2;
            else if(tree[i].child[j][1] == '-' && tree[i].child[j][2] == '-') tree[i].child[j][3] = 0;
            else tree[i].child[j][3] = 1;
        }
    }
    
    if(tree[0].node != tree[1].node) printf("No\n");
    else{
        for(int j=0; j<tree[0].node; j++){
            int flag = 0;
            for(int i=0; i<tree[0].node; i++){
                if(tree[0].child[j][0] == tree[1].child[i][0]){
                    if(tree[0].child[j][3] != tree[1].child[i][3]){
                        printf("No\n");
                        return 0;
                    }
                    if(flag == 0) flag = 1;
                }
            }
            if(flag == 0){
                    printf("No\n");
                    return 0;
                }
        }
        printf("Yes\n");
    }


    return 0;
}

#else

struct TNode{
	char Data;//字母 
	int Left,Right;//左右儿子编号 
};//建立树的结构体 
 
typedef struct TNode Tree;//typedef简化名称 
Tree t1[12],t2[12];//两棵树的数组用于比较 
 
int Read(Tree t[]){
	int i;
	int n;//节点个数 
	int pre[12];//祖先数组，用于判断树根
	int root = -1;//树根标号，初始化为-1
	memset(pre,0,sizeof(pre)) ;
	scanf("%d",&n);
	if(n){//如果n不为零执行 
		for(i = 0; i < n; i++){
			char l,r;//记录左右儿子的值 
			scanf(" %c %c %c",&t[i].Data,&l,&r);
			if(l!='-'){
				t[i].Left = l-'0';//如果是数字，左子树记录该数字
				pre[t[i].Left] = 1;//表示这个左孩子编号有父亲 
			}
			else{
				t[i].Left = -1;
			}
			if(r!='-'){//右边同理 
				t[i].Right = r-'0';
				pre[t[i].Right] = 1;
			}
			else{
				t[i].Right = -1;
			}
		} 
	}//记录完毕
	
	//找根
	for(i = 0; i < n; i++){
		if(!pre[i]){//如果有节点父亲是0，说明没父亲为树根 
			root = i;
			break;
		}
	} 
	return root;
} 
 
int isSame(int root1,int root2){
	if((root1 == -1) && (root2 == -1)){//树根都是空，同构返回1 
		return 1;
	}
	
	if(((root1 == -1) && (root2 != -1)) || ((root1 != -1) && (root2 == -1))){//如果一个是空一个不空，不同构，返回0 
		return 0;
	}
	
	if((t1[root1].Data) != (t2[root2].Data)){//如果树根值不同，不同构，返回0 
		return 0; 
	}
	
	if((t1[root1].Left == -1) && (t2[root2].Left == -1)){//如果左子树都是空的，判断右子树 
		return isSame(t1[root1].Right,t2[root2].Right);
	}
	
	if((t1[root1].Left != -1) && (t2[root2].Left != -1) && (t1[t1[root1].Left].Data == t2[t2[root2].Left].Data)){
                  //如果左树不空且左子树值想同，判断其左右子树 
		return (isSame(t1[root1].Left,t2[root2].Left) && isSame(t1[root1].Right,t2[root2].Right));
	}
	
    else{         //如果左子树有一个空的，或者两个树不空 左子树的值不同 ,交换左右子树判断 
    	return (isSame(t1[root1].Left,t2[root2].Right) && isSame(t1[root1].Right,t2[root2].Left)); 
	}
} 
 
int main(){
	
	int root1,root2;//树根节点编号 
	
	root1 = Read(t1);//读取 
	root2 = Read(t2);
	
    if(isSame(root1,root2))//判断是否同构 
       printf("Yes\n");
    else
       printf("No\n");
	return 0;
}
/*
————————————————
版权声明：本文为CSDN博主「一只二十四节气」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/codeswarrior/article/details/78503515 */

#endif
