/*
#include <stdio.h>
#include <stdlib.h>
#define  maxsize 10
typedef struct
{int data[maxsize];
    int front;
    int rear;
}SqQueue;

int InitQueue(SqQueue *q)
{
    q->front=0;
    q->rear=0;
    return 1;
}

int Queuelength(SqQueue q)
{
return (q.rear-q.front+maxsize)%maxsize;

}

int in(SqQueue *q,int e)
{if((q->rear+1)%maxsize==q->front)
    {return 0;}
q->data[q->rear]=e;
q->rear=(q->rear+1)%maxsize;
return 1;
}

int out(SqQueue *q, int *e)
{if(q->front==q->rear)
    {return 0;}
  *e = q->data[q->front];
  q->front=(q->front+1)%maxsize;
return 1;

} 

int main()
{
    SqQueue q;
    InitQueue(&q);

    printf("=== 测试入队 ===\n");
    for (int i = 1; i <= 5; i++) {
        if (in(&q, i * 10))
            printf("入队: %d, 当前队长: %d\n", i * 10, Queuelength(q));
        else
            printf("入队失败: %d (队满)\n", i * 10);
    }

    printf("\n=== 测试出队 ===\n");
    int val;
    while (out(&q, &val))
        printf("出队: %d, 剩余队长: %d\n", val, Queuelength(q));

    printf("\n=== 测试队满 ===\n");
    for (int i = 1; i <= 12; i++) {
        if (in(&q, i))
            printf("入队成功: %d\n", i);
        else
            printf("入队失败: %d (队满, 当前队长: %d)\n", i, Queuelength(q));
    }

    return 0;
}
*/