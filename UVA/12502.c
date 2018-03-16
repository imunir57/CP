#include<stdio.h>
int main()
{
    int t,x,y,z,m;
    scanf("%d",&t);
       while(t--){
            scanf("%d%d%d",&x,&y,&z);
            m=(z*(2*x-y))/(x+y);
            printf("%d\n",m);
        }

}

