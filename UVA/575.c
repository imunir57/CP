#include<stdio.h>
#include<string.h>
#include<math.h>
#define SA (pow(2,l--)-1)

///AC
int main() {
    char sk[35];
    double d;
    while(scanf("%s",sk)==1) {
        long long int i,l,len,sum=0;
        if(sk[0]=='0')
        break;

        len=l=strlen(sk);
        for(i=0; i<len; i++) {
            d=sk[i]-'0';
            d*=SA;
            sum+=d;
        }
        printf("%lld\n",sum);
    }
}

