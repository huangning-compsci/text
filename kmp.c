#include <string.h>
#include <stdio.h>
/*
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
            else{k=next[k];}        为了找一个更小的相等前后缀。因为本身就有大相等前后缀，
    }                               由于相等：前后缀是相等的，故找前缀的next值来快速判断是否有更小相等前后缀
    return 1;
}
*/

int Initnextval(int *nextval,char *p)
{
    int k=0;
    int i=1;
    
    nextval[1]=0;
    while(i<strlen(p))
    {
        if(p[i]==p[k]||k==0)
            {
                i++;
                k++;
                if(p[i]!=p[k])          //若相等，说明失配时这个子串里面准备比较的也必定不匹配，相当于(a1=a2=a && a1!=b1 )=>a2!=b1
                    nextval[i]=k;
                else
                    nextval[i]=nextval[k];  //等于nextval[k]的原因：相当于先做一步k=nextval[k]，换了一个更小的相等前后缀
            }
            else{k=nextval[k];}        /*为了找一个更小的相等前后缀。因为本身就有大相等前后缀，
                            由于相等：前后缀是相等的，故找前缀的next值来快速判断是否有更小相等前后缀*/
    }                               
    return 1;
}

int kmp(char *big,char *sma)
{int nextval[100];
Initnextval(nextval,sma);
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
                j=nextval[j];
            }    
    }

if(j<strlen(sma))
    return i-j;
else
    return 0;

}
