#include <stdio.h>

///AC
int main() {
    int a,c,d;
    while(scanf("%d",&a)==1) {
        if(a==0)
            break;
        int ans=0;
        while(a>2) {
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

