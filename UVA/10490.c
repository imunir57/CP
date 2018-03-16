#include<stdio.h>
#include<math.h>
#define D pow(2,(a-1))*(pow(2,a)-1)
int main()
///AC
{
    int a;

    while(scanf("%d",&a)==1){
    if(a==0)
        break;
    else if(a==31)
        printf("Perfect: 2305843008139952128!\n");
    else if(a==1||a==2||a==3||a==5||a==7||a==13||a==17||a==19){
        printf("Perfect: %.lf!\n",D);
    }
    else if(a==11||a==23||a==29)
        printf("Given number is prime. But, NO perfect number is available.\n");
    else
        printf("Given number is NOT prime! NO perfect number is available.\n");

    }
}
