#include<stdio.h>
int main()
{
    int n,i,sum;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n)<100){
            if(n==0){
        printf("END OF OUTPUT\n");
        break;
    }
            sum=0;
           for(i=1;i<n;i++){
                if(n%i==0){
                 sum+=i;
        }
            }
       if(sum==n){
        printf("%5d  PERFECT\n",n);
       }
       else if(sum<n){
        printf("%5d  DEFICIENT\n",n);
       }
       else{
    printf("%5d  ABUNDANT\n",n);}
}
    return 0;
}