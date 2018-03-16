#include<stdio.h>
#define E1 (n*n+n)/2
#define E2 (b*b+b)/2+(x*x-x)/2
///AC
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,x,a,b;
        tc++;
        scanf("%d%d%d",&n,&k,&x);
        b=k+x-1;
        a=E1-E2;
        printf("Case %d: %d\n",tc,a);

    }
}

