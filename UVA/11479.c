#include<stdio.h>
///AC
int main() {
    int t,tc=0;
    scanf("%d",&t);
    while(t--) {
        tc++;
        long long int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a+b>c&&a+c>b&&b+c>a) {
            if(a==b&&b==c)
                printf("Case %d: Equilateral\n",tc);
            else if(a==b||b==c||c==a)
                printf("Case %d: Isosceles\n",tc);

            else
                printf("Case %d: Scalene\n",tc);
        }
        else
            printf("Case %d: Invalid\n",tc);
    }
}
