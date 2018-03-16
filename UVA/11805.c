#include<stdio.h>
///AC
int main() {
    int t,n,k,p,tc=0;
    scanf("%d",&t);
    while(t--) {
        tc++;
        int i,j;
        scanf("%d%d%d",&n,&k,&p);
        j=k;
        for(i=0; i<p; i++) {
            if(j==n)
                j=0;
            j++;

        }
        if(j==0)
            printf("Case %d: %d\n",tc,n);
        else
            printf("Case %d: %d\n",tc,j);
    }
}

