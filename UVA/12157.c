#include<stdio.h>
#define C1 (i/30+1)*10
#define C2 (i/60+1)*15
///AC
int main() {
    int t,tc=0;
    scanf("%d",&t);
    while(t--) {
        tc++;
        int n,i,mile=0,juice=0;
        scanf("%d",&n);
        while(n--) {
            scanf("%d",&i);
            mile+=C1;
            juice+=C2;
        }
        if(mile<juice)
            printf("Case %d: Mile %d\n",tc,mile);
        else if(mile>juice)
            printf("Case %d: Juice %d\n",tc,juice);
        else
            printf("Case %d: Mile Juice %d\n",tc,mile);

    }
}

