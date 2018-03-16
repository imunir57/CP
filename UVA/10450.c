#include <stdio.h>

int main()
{
   unsigned long long int a,b,c;
   int n,i,m=1,t;
   scanf("%d",&t);
   while(t--){
        scanf("%d",&n);

    n+=2;
    for(i=0,a=0,b=1;i<n;i++)
    {
        c=a;
        a+=b;
        b=c;


    }
    printf("Scenario #%d:\n%llu\n\n",m,a);
    m++;
   }

    return 0;
}



