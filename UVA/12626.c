#include<stdio.h>
///AC
int main() {
    int t;
    scanf("%d",&t);
    getchar();
    char p;
    while(t--)
    {
        int i,sm=601,pizza[6]={};
        while(scanf("%c",&p)==1)
        {
            if(p=='\n')
                break;
            if(p=='A')
                pizza[0]++;
            else if(p=='R')
                pizza[1]++;
            else if(p=='M')
            pizza[2]++;
            else if(p=='G')
            pizza[3]++;
            else if(p=='I')
            pizza[4]++;
            else if(p=='T')
            pizza[5]++;
        }
        pizza[0]/=3;
        pizza[1]/=2;
        for(i=0;i<6;i++)
        {
            if(pizza[i]<sm)
                sm=pizza[i];
        }
        if(pizza[0]>=sm&&pizza[1]>=sm&&pizza[2]>=sm&&pizza[3]>=sm&&pizza[4]>=sm&&pizza[5]>=sm)
           printf("%d\n",sm);
           else
            printf("%d\n",--sm);

}}


