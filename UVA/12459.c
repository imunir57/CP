#include <stdio.h>

int main()
{
   unsigned long long int a,b,c;
   int n,i;
   while(scanf("%d",&n)!=EOF){
       if(n==0||n>80)
       break;

    for(i=-1,a=0,b=1,c=0;i<n;i++)
    {
        c=a;
        a+=b;
        b=c;


    }
    printf("%llu\n",a);
   }

    return 0;
}


