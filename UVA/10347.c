#include <stdio.h>
#include <math.h>
#define S (a+b+c)/2
#define H s*(s-a)*(s-b)*(s-c)
#define M sqrt(H)*4/3
#define P2 printf("%.3lf\n",m)
///AC
int main() {
    double a,b,c,s,m;
    while(scanf("%lf%lf%lf",&a,&b,&c)==3) {
        s=S;
        if(H<=0)
            m=-1;
        else
            m=M;
        P2;
    }
    return 0;
}
