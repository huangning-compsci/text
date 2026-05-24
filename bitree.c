#include <stdio.h>
#include <stdlib.h>
#define OK 1;
#define Big 65550;

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

//邻接矩阵
typedef struct
{
    int value;
    
}GraphNode;

typedef struct
{
  int Numnode,Numline;
  GraphNode vertex[100],matrix[100][100];
  
  
}Matrix;

int InitMatrix(Matrix *T)
{
scanf(&T->Numnode,&T->Numline);
for(int i=0;i<T->Numnode;i++)
    {scanf(&T->vertex[i]);}
for (int j=0;j<T->Numnode;j++)
    {
        for (int k=0;k<T->Numnode;k++)
            {T->matrix[j][k].value=Big;}
    }
for (int l=0;l=T->Numline;l++)
    {   int value,line,column;
        printf("请依次输入元素值，行数，列数（以0开始）");
        scanf(&value,&line,&column);
        T->matrix[line][column].value=value;

    }        
return 1;
}

//邻接表
typedef struct ListNode
{
    int index;
    struct ListNode *next;
}ListNode,*ListNodeptr;

typedef struct ListElem
{
    int data;               //指的是顶点信息，即存储V0这个顶点；
    ListNodeptr Firstout;
    
}List;

typedef struct 
{
    int lenNode,lenline;
    List Gra[10];
     
}GraphList;

int InitGraphList(GraphList *T)
{   
    ListNodeptr p;
    int i,j;
    printf("请输入邻接表的顶点数与边数");
    scanf(&T->lenNode,&T->lenline);
    
    for(int k=0;k<T->lenNode;i++)
        {
            scanf(&T->Gra[k].data);             //初始化顶点
            T->Gra[k].Firstout=NULL;
        }
                                                            //让我震撼的地方：我原本想用while，输入一个顶点和与其相连顶点。
    for(int l=0;l<T->lenline;l++)                           //但是应该把顶点与边的初始化分开（第一性原理），代码量增加了but可读性提升and逻辑清晰了
        {
            printf("请输入有向边（v1,v2）上的顶点序列\n");     
            scanf("%d,%d",&i,&j);           //优化后：输入一条边就初始化一条，具有普适性
            p=(ListNodeptr)malloc(sizeof(ListNode));    //头插法
            p->index=j;
            p->next=T->Gra[i].Firstout;
            T->Gra[i].Firstout=p;
        }    
    return 1;
}
