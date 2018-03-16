#include <stdio.h>
#define P1 printf("Underflow!\n")
#define P2 printf("Overflow!\n")
#define C j=i*j

int main() {
    int n,i;
    long long int j;
    while(scanf("%d",&n)==1){
            j=1;
    if(n<8&&n>-1)
       P1 ;
    else if(n<0)
        if(n%2==0)
        P1;
        else
            P2;
    else if(n>13)
        P2;
    else{
    for(i=1;i<=n;i++)
        C;
    printf("%lld\n",j);
    }
    }
    return 0;
}


