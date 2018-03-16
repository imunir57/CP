#include <stdio.h>
#define I scanf("%d",&t)
#define AB scanf("%d%d",&a,&b)
#define p printf("Case %d: %d\n",c,sum)
#define X (b+1)>>1
#define Y a>>1
#define S x*x-y*y

int main()
{
    int t,a,b,sum,c=1,x,y;
    I;
    while(t--)
    {

        AB;
        x=X;
        y=Y;
        sum=S;
        p;
        c++;
    }
    return 0;
}

