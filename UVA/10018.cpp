#include <stdio.h>
#define uli unsigned long long int
#define A rev = rev * 10
#define B rev = rev + n%10
#define C n= n/10
int main()
{ ///AC
    uli a,rev,n;
    int i,j;
    scanf("%d",&j);
    while(j--)
    {
        i=0;
        scanf("%llu",&a);
        if(a==196)
            break;
        while(1)
        {
            n=a;
            rev=0;

            while(n!=0)

            {
                A;
                B;
                C;

            }

            if(a==rev)
                break;
            else
                a+=rev;

            i++;

        }
        printf("%d %llu\n",i,rev);
    }
    return 0;
}
