#include<stdio.h>

int main()///AC
{
    int c,n,i,sum,num[1000],con;
    double avg,k;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&n);
        sum=0;
        con=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            sum+=num[i];
        }
        avg=(double)sum/n;
        for(i=0;i<n;i++)
        {
            if(num[i]>avg)
                con++;
        }
        k=(double)con/n;
        printf("%.3lf%%\n",k*100);
    }
    return 0;
}
