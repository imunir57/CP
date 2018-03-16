#include <stdio.h>
#include <stdlib.h>
int the3n(int n)
{
    if(n==1)return 1;
    else if(n&1)
        return the3n(3*n+1)+1;
    else
        return the3n(n/2)+1;
}

int main() {
    int c,a,b;
    while(scanf("%d %d",&a,&b)==2)
    {
        int max=0;
        while(a<=b)
        {
           c=the3n(a);
           if(c>max)
            max=c;
        a++;
        }
        printf("%d\n",max);
    }


    return 0;
}
