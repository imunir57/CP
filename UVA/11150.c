#include <stdio.h>

///AC
int main() {
    int a,c,d;
    while(scanf("%d",&a)==1){
    int ans=a;
    while(a>=2)
    {
        c=a%3;
        d=a/3;
        ans+=d;
        a=d+c;
        if(a==2)
            a++;
    }
    printf("%d\n",ans);
    }


    return 0;
}


