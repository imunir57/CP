#include <stdio.h>
#include <math.h>
//Accepted
int main()
{
    double p,k,i=pow(10,101);
    int n;

    while(scanf("%d %lf",&n,&p)!=EOF)
    {
        if(n<1 || n>200 || p<1 || p>i)
            break;
        k=pow(p,(double)1/n);
        printf("%.0lf\n",k);
    }

    return 0;
}

