#include<stdio.h>
///AC

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,b=0,s=0;
        tc++;
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<n;i++)
        {
            if(a[i-1]>a[i])
                b++;
            else if(a[i-1]<a[i])
                s++;
        }
        printf("Case %d: %d %d\n",tc,s,b);
    }
}

