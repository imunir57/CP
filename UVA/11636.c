#include<stdio.h>
#include<math.h>
///AC
int main()
{
    int n,tc=0;
    double i;
    while(scanf("%d",&n)==1&&n>0){
            tc++;
    i=ceil(log(n)/log(2));
    printf("Case %d: %.0lf\n",tc,i);
    }
}
