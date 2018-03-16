#include<stdio.h>
///AC
int func(int n) {
    int sum=0;
    while(n>0) {
        sum+=n%10;
        n/=10;
    }
    if(sum>=0&&sum<10)
        return sum;
    else
        func(sum);
}
int main() {
    unsigned int a;
    int res;
    while(scanf("%u",&a)==1) {
        if(a==0)
            break;
        res=func(a);
        printf("%d\n",res);
    }

}

