#include <stdio.h>

///AC
int main() {
    int a,b,c,d;
    while(scanf("%d%d",&a,&b)==2){
    int ans=a;
    while(a>(b-1))
    {
        c=a%b;
        d=a/b;
        ans+=d;
        a=d+c;
    }
    printf("%d\n",ans);
    }


    return 0;
}
