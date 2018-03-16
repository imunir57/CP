#include <stdio.h>
#define ULL unsigned long long int
#define P1 printf("No carry operation.\n");
#define P2 printf("1 carry operation.\n");
#define P3 printf("%llu carry operations.\n",c);
int main()
{
    ULL a, b, i, c,x,y,d;
    while(scanf("%llu%llu",&a,&b)==2)
    {

        if(a==0 && b==0)
            break;
        c=0,d=0;
        while(a!=0 || b!=0)
        {
            x=a%10;
            y=b%10+d;
            a=a/10;
            b=b/10;

            if((x+y)>9)
            {
                c++;
                d=1;
            }
            else
                d=0;
        }
        if(c==0)
            P1
        else if(c==1)
            P2
        else
            P3
    }
    return 0;
}
