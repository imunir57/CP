#include <stdio.h>
#define S scanf("%d %d %d",&a,&b,&c)
#define C (a+b)>c && (a+c)>b && (b+c)>a
#define P1 printf("OK\n")
#define P2 printf("Wrong!!\n")
int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        S;
        if(C)
            P1;
        else
            P2;

    }

    return 0;
}

