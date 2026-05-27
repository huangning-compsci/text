#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define OK 1;

#define MAXVEX 9;

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

typedef enum{Link,Thread} Tag; 
typedef struct BitNode
{
    int data;
    struct BitNode *Lchild,*Rchild;
    Tag LTag,RTag;
}BitNode,*BiTree;

BiTree pre;
static InitTree(BiTree p)
{
    if(p)               //检测是否p为空，很重要，搭配递归
        {
        InitTree(p->Lchild);
        if(!p->Lchild)
            {
                p->LTag=Thread;
                p->Lchild=pre;
            } 
        if(!pre->Rchild)
            {
                pre->RTag=Thread;
                pre->Rchild=p;
            }
        pre=p;
        InitTree(p->Rchild);        
        }
    return OK;
}

static InOrder(BiTree Head)
{   BiTree p=Head->Lchild;
    while(p!=Head)             
        {
        while(!p->LTag)
            {p=p->Lchild;}
        printf("%c",p->data);       //无左才输出
        while(p->RTag&&p->Rchild!=Head)     //是p->Rchild!=Head,而非p
            {                                //p的右空则开始跳跃，直至遇到一个有右子树的节点，跳跃后的节点左子树肯定是被遍历过的
                p=p->Rchild;                
                printf("%c",p->data);
            }  
        p=p->Rchild;                //进入树的右分支，配合循环，看作对一个以p为根节点的子树的遍历；
        }
}

