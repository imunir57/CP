#include<stdio.h>
///AC
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--)
    {
        tc++;
        int l,i;
        scanf("%d",&l);
        int a[l];
        for(i=0;i<l;i++)
            scanf("%d",&a[i]);
        printf("Case %d: %d\n",tc,a[l/2]);
    }
}
