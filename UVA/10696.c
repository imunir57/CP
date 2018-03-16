#include<stdio.h>
#define LIM 100
#define M n-10
#define lli long long int
#define P1 printf("f91(%lld) = 91\n",n)
#define P2 printf("f91(%lld) = %lld\n",n,M)
int main()
{
    lli n;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;
        if(n<=LIM)
            P1;
        else
            P2;

    }
    return 0;
}
