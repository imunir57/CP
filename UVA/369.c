#include<stdio.h>
#define CAl (double)n/m
///AC
int main()
{
    int n,m,i,k,l;
    while(scanf("%d%d",&n,&m)==2){
            if(n==0&&m==0)
            break;
            k=n;
            l=m;
    double fact=1;
    for(i=n;n>n-m;n--,m--)
        fact*=CAl;
    printf("%d things taken %d at a time is %.lf exactly.\n",k,l,fact);
    }
}

