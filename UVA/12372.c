#include<stdio.h>
///AC
int main()
{
    int a,b,c,t,tc=0;
    scanf("%d",&t);
    while(t--)
    {
        tc++;
        scanf("%d%d%d",&a,&b,&c);
        if(a>20||b>20||c>20)
            printf("Case %d: bad\n",tc);
         else
            printf("Case %d: good\n",tc);
    }
}

