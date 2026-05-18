#include <string.h>
#include <stdio.h>

int Initnext(int *next,char *p)
{
    int k=0;
    int i=1;
    
    next[1]=0;
    while(i<strlen(p))
    {
        if(p[i]==p[k]||k==0)
            {
                i++;
                k++;
                next[i]=k;
            }
            else{k=next[k];}        /*为了找一个更小的相等前后缀。因为本身就有大相等前后缀，
    }                               由于相等：前后缀是相等的，故找前缀的next值来快速判断是否有更小相等前后缀*/
    return 1;
}

int kmp(char *big,char *sma)
{int next[100];
Initnext(next,sma);
int i=0,j=0;
while(i<strlen(big)&&j<strlen(sma))
    {
        if(big[i]==sma[j]||j==0)
            {
                i++;
                j++;
            }
        else
            {
                j=next[j];
            }    
    }

if(j<strlen(sma))
    return i-j;
else
    return 0;

}
