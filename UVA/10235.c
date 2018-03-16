#include <stdio.h>
#include<math.h>
///AC
int prime(int p) {
    int i,rt;
    rt=sqrt(p)+1;
    if(p==2)
        return 1;
    else if(p%2==0)
        return 2;
    else {
        for(i=2; i<=rt; i++)
            if(p%i==0)
                break;
    }
    if(i==(rt+1))
        return 1;
    else
        return 2;

}
int rev(int r) {
    int re=0,a,j=r;
    while(r!=0) {
        re = re * 10;
        re = re + r%10;
        r= r/10;
    }
    if(j==re)
        return 3;
    else{
    a=prime(re);
    if(a==1)
        return 4;
    else
        return 3;
    }
}
int main() {
    int n,a,r;
    while(scanf("%d",&n)==1) {
        a=prime(n);
        if(a==1) {
            r=rev(n);
            if(r==4)
                printf("%d is emirp.\n",n);
            else
                printf("%d is prime.\n",n);

        } else
            printf("%d is not prime.\n",n);
    }
    return 0;
}
