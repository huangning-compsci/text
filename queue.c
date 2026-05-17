/*
#include <stdio.h>
#include <stdlib.h>
typedef struct queuenode
{int data;
 struct queuenode *next;   
}queuenode,*Linkqueueptr;

typedef struct Linkqueue
{
    Linkqueueptr front,rear;
}Linkqueue;

int Initqueue(Linkqueue *q)
{   Linkqueueptr head=(Linkqueueptr)malloc(sizeof(queuenode));
    head->next=NULL;
    q->front=head;
    q->rear=head;
    return 1;
}

int in(Linkqueue *q,int e)
{Linkqueueptr p=(Linkqueueptr)malloc(sizeof(queuenode));

p->data=e;
p->next=NULL;
q->rear->next=p;
q->rear=p;
return 1;
}

int out(Linkqueue *q,int *e)
{   Linkqueueptr p=q->front->next;
    if(q->rear==q->front)
        return 0;
    *e=q->front->data;
    q->front->next=p->next;
    if(q->rear==p)         //这里的判断很容易忘记，边界情况，一般的out不会波及尾节点
        q->rear=q->front;
    free(p);
    return 1;
}
    */