#include <stdio.h>
#include <stdlib.h>
typedef struct BitNode
{
    int data;
    struct BitNode *Lchild,*Rchild;
}BitNode,*BiTree;

void InitBiTree(BiTree *T)
{char in;
scanf("%c",&in);
if(in=='#')
    *T=NULL;
     
else
    {
        *T=(BiTree)malloc(sizeof(BitNode));
        (*T)->data=in;
        InitBiTree(&(*T)->Lchild);
        InitBiTree(&(*T)->Rchild);

    }
}

//前序遍历
void PreOrder(BiTree T)
{
    if(T==NULL)
        return;
    else
        {
            printf("%c",T->data);
            preorder(T->Lchild);        //Lchild就是一个指针变量，因此不用打&来表示传值
            preorder(T->Rchild);
        }    
}

//树的双亲表示法
typedef struct PTNode
{
    int data;
    int parent;
}PTNode;

typedef struct PTree
{
    PTNode node[100];
    int r,n;
}PTree;

//孩子表示法
typedef struct CTnode
{
    int child;      //自己在数组中的下表
    struct CTnode *next;
}*CTnodeptr;

typedef struct Firstchild
{
    int data;
    CTnodeptr firstchild;
}CTBox;

typedef struct CTree 
{
    CTBox node[100];

}CTree;