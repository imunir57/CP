#include <stdio.h>
#define lli long long int
#define p1 printf(">\n");
#define p2 printf("<\n");
#define p3 printf("=\n");

int main()
{
    int t;
    lli a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        if(a>b)
            p1
            else if(a<b)
                p2
                else
                    p3
                }

}
