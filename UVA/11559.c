#include <stdio.h>
#define MAX 1000000000
int main()///AC
{
    int n,b,h,w,p,i,j,m,a[13],c,val;

    while(scanf("%d%d%d%d",&n,&b,&h,&w)==4)
    {
        m=MAX;

        for(i=0; i<h; i++)
        {


            scanf("%d",&p);
            val=n*p;
            for(j=0; j<w; j++)
                scanf("%d",&a[j]);
            for(j=0; j<w; j++)
            {
                if(b>=val)
                {
                    if(n<=a[j])
                    {
                        c=val;
                        if(c<m)
                            m=c;
                    }
                }
                else
                    break;
            }

        }


        if(m==MAX)
            printf("stay home\n");
        else
            printf("%d\n",m);

    }
    return 0;
}



