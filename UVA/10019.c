#include <stdio.h>

int main()
{
    int n,a,c,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &n);
        int   con=0,hex=0;

        for (c = 15; c >= 0; c--)
        {
            k = n >> c;

            if (k & 1)
                con++;
        }

        while(n!=0)
        {
            a=n%10;
            for (c = 15; c >= 0; c--)
            {
                k = a >> c;

                if (k & 1)
                    hex++;
            }
            n/=10;
        }
        printf("%d %d\n",con,hex);
    }

    return 0;
}
