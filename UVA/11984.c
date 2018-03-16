#include <stdio.h>
#define P1 printf("Case %d: %.2lf\n",tc,f)
#define NUM 0.5555556
///AC
int main() {
    int c,d,t,tc=0;
    double i,f;
    scanf("%d",&t);
    while(t--) {
        tc++;
        scanf("%d%d",&c,&d);
        i=NUM*d;
        f=(double)(c+i);
        P1;
    }

    return 0;
}


