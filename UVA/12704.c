#include <stdio.h>
#include <math.h>
#define A sqrt(x*x+y*y)
///AC
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double sm,lrg;
        int x,y,r;
        scanf("%d%d%d",&x,&y,&r);
        sm=r-A;
        lrg=r+A;
        printf("%.2lf %.2lf\n",sm,lrg);

    }


    return 0;
}

