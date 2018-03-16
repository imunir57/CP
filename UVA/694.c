#include <stdio.h>
#define C1 i>>=1
#define C2 i=3*i+1
#define P printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n",cs,n,j,m)
///AC
int main() {
    long long int i,j,m,n;
    int cs=0;

    while(scanf("%lld%lld",&i,&j)!=EOF) {
        if(j<0&&i<0)
            break;
        cs++;
        n=i;
        m=1;

        while(i!=1) {
            if(i%2==0)
                C1;
            else
                C2 ;
            if(i>j)
                break;

            m++;

        }

        P;

    }


    return 0;
}
