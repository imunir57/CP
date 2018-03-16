#include <stdio.h>
#include<math.h>
#define pi acos(-1)
int main() ///AC
{
    unsigned int t,x;
    double y,r,red,green;
    scanf("%u",&t);
    while(t--){
    scanf("%u",&x);
    y=(double)x*0.6;
    r=y/3;
    red=pi*r*r;
    green=x*y-red;
    printf("%.2lf %.2lf\n",red,green);
    }

    return 0;
}



