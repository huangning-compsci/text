#include <stdio.h>
#include <stdlib.h>
typedef struct stacknode
{
  int data;
  struct stacknode *next;

}stacknode,*Linkstackptr;

typedef struct 
{
    Linkstackptr top;
    int count;
}Linkstack;

int pop(Linkstack *s)
{Linkstackptr p=s->top;
   s->top=s->top->next;
   free(p);
   s->count--; 
return 1;
}

int add(Linkstack *s,int e)
{Linkstackptr n=(Linkstackptr)malloc(sizeof(stacknode));
n->data=e;
n->next=s->top;
s->top=n;
s->count++;
return 1;
}

int main()
{int input=0,count=1;
 Linkstack *student=(Linkstack*)malloc(sizeof(Linkstack));
 student->top=NULL;
 student->count=0;
 while(1)
 {scanf("%d",&input);
    if(input==-1) break;
    if(count==1)
    {Linkstackptr n=(Linkstackptr)malloc(sizeof(stacknode));
n->data=input;
n->next=NULL;
student->top=n;
count++;
student->count++;
}
else
{add(student,input);}


}

printf("%d",student->top->data);
return 0;
}