
#include <stdio.h>
#include <stdlib.h>
typedef struct node        /*这个结构类型包括三个域 */
{    int number;        /*猴子的编号*/
    int mydata;        /* 猴子的定数 */
    struct node *next; /* 指向下一只猴子的指针 */
} linklist;
linklist *CreateCircle( int n );
linklist *DeleteNext(linklist *p);   /* 删除单循环链表的p所指的下一个结点 */

/* 提示： 你所有的代码将由系统插入在此处 */
int KingOfMonkey(int n, linklist *head) {
    // 只剩一只猴子（循环链表中自己指向自己）
    if (head->next == head)
        return head->number;
    
    // 向前移动 n-1 步，head 停在待删除节点的前一个
    for (int i = 0; i < n - 1; i++) {
        head = head->next;
    }

    linklist *s = DeleteNext(head);
    if (s == NULL)
        return -1;  // 异常处理

    return KingOfMonkey(s->mydata, s->next);
}

linklist *CreateCircle(int n) {
    // 创建 n 个节点的循环链表
    linklist *head = NULL, *tail = NULL;
    for (int i = 1; i <= n; i++) {
        linklist *p = (linklist *)malloc(sizeof(linklist));
        p->number = i;
        scanf("%d", &p->mydata);  // 读入每只猴子的定数
        p->next = NULL;
        if (head == NULL) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }
    tail->next = head;  // 形成循环
    return tail;        // 返回最后一个节点
}

/* 删除 p 所指节点的下一个结点，返回被删结点的指针 */
linklist *DeleteNext(linklist *p) {
    linklist *q = p->next;      // q 是要删除的节点
    printf("删除%d\n",q->number);
    p->next = q->next;           // 跳过 q
    return q;                    // 返回被删节点
}
int main()
{
    linklist *head;
    int i,n;
    scanf("%d",&n); 
    head = CreateCircle(n); /*创建单向循环链表，返回最后一个结点的指针 */
    printf("The king is monkey[%d].\n", KingOfMonkey(n,head));
    return 0;
}
/* 请在这里填写答案 */