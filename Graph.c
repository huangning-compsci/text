#include <stdio.h>
#define Big 65535;

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

//深度优先遍历（邻接矩阵）

 int visited[9];        //!这么写会浪费空间，要学习怎么使用bool
 void DFSMatrix(Matrix T,int i)
 {
    int j;                                  
    visited[i]=1;               //进入i就标记i
    for (j=0;j<T.Numnode;j++)       
        if(T.matrix[i][j].value==1&&!visited[j])
            DFS(T,j);           //深度优先意味着有就一直往深进入，
}                               //这个算法递归到当前顶点没有其他未标记顶点可进入就结束

void DFSTraverse(Matrix T)
{
    for(int i=0;i<T.Numnode;i++)        //初始化visited为0
        visited[i]=0;
    for(int j=0;j<T.Numnode;j++)        //对于每个顶点，未被遍历过就从他开始进行DFS递归
        if(!visited[j])
            DFS(T,j);
}

//深度优先算法（邻接表）
/*  我的错误思路
void DFSList(GraphList T,int i)
{
    int j;
    visited[i]=1;
    for(j=0;j<T.lenNode;j++)
        if(T.Gra[j].data==1&&!visited[j])
            DFSList(T,j);
}
*/

void DFSList(GraphList T,int i)         //传指针的话可以优化性能
{
    ListNodeptr p;                      
    visited[i]=0;
    p=T.Gra[i].Firstout->next;     
    while (p)                            //如果有下一个，
        {
            if(!visited[p->index])      //就检查这个是否来过，没来过就进入（进入更深）
                DFS(T,p->index);
            p=p->next;                  //来过就选择去链表下一个结点
        }
}


void DFSLTraverse(GraphList T)
{
    for(int i=0;i<T.lenNode;i++)
        visited[i]=0;
    for(int i=0;i<T.lenNode;i++)
        if(!visited[i])             //每一个顶点如果进入过就会被跳过，代码简洁可读
            DFS(T,i);    
}

//广度优先算法-矩阵
typedef struct 
{
    int data;
    int front;
    int rear;
}Queue;

void BFSM(Matrix T)
{   
    Queue p;
    InitQueue (&p);
    for(int i=0;i<T.Numnode;i++)
        visited[i]=0;
    
    for(int i=0;i<T.Numnode;i++)    //感觉像一个保障，有孤立点才会在循环中再次停留
        {
            if(!visited[i])         //与循环配合的条件
                {
                    visited[i]=1;       //遇到就要标记，是算法实现的基础
                    Enqueue(&p,i);  
                    while(!QueueEmpty(p))   
                        {
                            dequeue(&p,&i);     //!这里的i返回值是关键，修改了i
                            for(int j=0;j<T.Numnode;j++)    //!，使后面的for循环改变了内涵，变成以被弹出顶点为核心了
                                {
                                    if(T.matrix[i][j].value=1&&!visited[j])
                                        {
                                            Enqueue(&p,j);
                                            visited[j]=1;
                                        }
                                }
                        }
                }
        }    
}

//广度优先算法-邻接表
void BFSL(GraphList GL)
{
    ListNodeptr p;
    Queue q;
    for(int i=0;i<GL.lenNode;i++)
        visited[i]=0;
    InitQueue(&q);
    for(int i=0;i<GL.lenNode;i++)
        {
            if(!visited[i])
                {
                    visited[i]=1;
                    Enqueue(&q,i);
                    while(!QueueEmpty(q))       //没空就一直出
                        {
                            dequeue(&q,&i);
                            p=GL.Gra[i].Firstout;       //!p指向刚弹出的顶点的邻接头指针，用于遍历来让与其相连的下层顶点入队列
         
                            while(p)                           //!重点思想，当该顶点没有后续邻接顶点后结束循环
                //错误示例： for(int j=0;j<GL.lenNode;j++)  遍历顶点个数次，暴力保障连接了很多顶点的极限情况，很浪费时间  
                                {
                                    if(!visited[p->index])
                                        {
                                            visited[p->index];
                                            Enqueue(&q,p->index);
                                        }
                                    p=p->next;    //换下一个邻接顶点
                                }
                        }
                }
        }
}

//最小生成树算法
void MiNispanTree_prim(Matrix T)
{
    int mincost[10];       //mincost数组存储当前生成树到i顶点的最小距离
    int node[10];          //node数组存储的是到i顶点距离最近的顶点的下标
    mincost[0]=0;           
    node[0]=0;             //以v0顶点为树根
    for(int i=1;i<T.Numnode;i++)
        {
            mincost[i]=T.matrix[0][i].value;   //当前生成树到任何顶点的最小距离即为v0到任意顶点的距离 
            node[i]=0;
        }
     //!接下来的是实现算法的重要部分   

     //!大循环：设计轮次数和未加入树的顶点个数相同，保证让每个顶点都进入最小生成树
    for(int i=1;i<T.Numnode;i++)        //i=1因为v0已经初始化完毕
        {   
            int j=1,k=0;        
            int Min=65535;
            //!第一个小循环：找出当前轮次的最小距离    
            while(j<T.Numnode)
                {
                    if(mincost[j]!=0&&mincost[j]<Min)    //寻找所有距离中的最小值
                        {   
                            Min=mincost[j];         
                            k=j;            //k记录当前轮次的离树最近距离的顶点下表
                        }
                    j++;                
                }
            printf("(%d,%d)",node[k],k);            //打印出连接的边，标记k顶点已经被链接
            node[k]=0;
            //!第二个小循环：看看k进入后各个顶点离树最小距离是否要改变        
            for(int i=1;i<T.Numnode;i++)            
                {
                    if(mincost[i]!=0&&T.matrix[k][i].value<mincost[i])      //!查看k顶点进入树后，各顶点离树最近距离是否改变
                        {
                            node[i]=k;
                            mincost[i]=T.matrix[k][i].value;
                        }
                }
        }
}

//克鲁斯卡尔算法（以边为目标来构建）
int Find(int *parent,int f)
{
    while(parent[f]>0)    
        {
            f=parent[f];
        }
    return f;  

}

typedef struct 
{
    int begin;
    int end;
    int weight;
}Edge;

void MinispanTree_Kruskal(GraphList T)            //还未实现将邻接表转换成按权值排列的边表
{   Edge edges[10];
    int parent[10];
    for(int i=0;i<T.lenNode;i++)
            parent[i]=0;
    for(int i=0;i<T.lenline;i++)
        {
            int n=find(parent,edges[i].begin);
            int m=find(parent,edges[i].end);
            if(n!=m)
                {
                    parent[n]=m;
                }
        }    

}
#define MAXVEX 3
//最短路径，弗洛伊德算法
typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];
void ShortPath_floyd(Matrix G,Patharc *D,ShortPathTable *P)
{
    int k,v,w;
    for(v=0;v<G.Numnode;v++)
        {
            for(w=0;w<G.Numnode;w++)
                {
                    (*D)[v][w]=G.matrix[v][w].value;
                    (*P)[v][w]=w;
                }
        }
    for(w=0;w<G.Numnode;w++)
        for(v=0;v<G.Numnode;v++)
            for(k=0;k<G.Numnode;k++)
                    if((*D)[w][v]>(*D)[w][k]+(*D)[k][v])
                        {
                            (*D)[w][v]=(*D)[w][k]+(*D)[k][v];
                            (*P)[w][v]=(*P)[w][k];
                        }
            
                
    
}
