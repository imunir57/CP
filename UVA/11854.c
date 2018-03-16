#include <stdio.h>
#include <math.h>
#define C1 a==0&&b==0&&c==0
#define M1 sqrt(a*a+b*b)
#define M2 sqrt(a*a+c*c)
#define M3 sqrt(c*c+b*b)
#define P1 printf("right\n")
#define P2 printf("wrong\n")
///AC
int main() {
    int a,b,c;
    double d,f,g;
    while(scanf("%d%d%d",&a,&b,&c)==3)
    {
        if(C1)
            break;
        d=M1;
        f=M2;
        g=M3;
        if(c==d||a==g||b==f)
            P1;
        else
            P2;
    }
    return 0;
}



