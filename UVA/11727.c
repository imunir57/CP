#include <stdio.h>


int main()
{
    int t,cas=1;
    long long int a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);

        if(a>b)
        {
            if(c>a)
                printf("Case %d: %lld\n",cas,a);
            else
            {
                if(b>c)
                    printf("Case %d: %lld\n",cas,b);
                else
                    printf("Case %d: %lld\n",cas,c);

            }

        }

        else
        {
            if(c>b)
                printf("Case %d: %lld\n",cas,b);

            else
            {
                if(c>a)
                    printf("Case %d: %lld\n",cas,c);
                else
                    printf("Case %d: %lld\n",cas,a);

            }

        }
        cas++;
    }

    return 0;
}

