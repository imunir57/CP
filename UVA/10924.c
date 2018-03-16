#include <stdio.h>
#define P1 printf("It is a prime word.\n")
#define P2 printf("It is not a prime word.\n")
#define C1 word[i]>='a'&&word[i]<='z'
#define C2 word[i]>='A'&&word[i]<='Z'
#define E1 val=word[i]-96
#define E2 val=word[i]-38
///AC
int prime(int n)
{
    int i;
    if(n==2||n==1)
        return 1;
    else if(n%2==0)
        return -1;
    else
    {
        for(i=2;i<n;i++){
            if(n%i==0)
            break;
            }
    if(i==n)
        return 1;
    else
        return -1;
    }
}

int main()
{
    char word[20];
    while(scanf("%s",word)!=EOF){
    int i,val,sum=0;
    for(i=0;word[i]!='\0';i++)
    {
        if(C1)
            E1;
        else if(C2)
            E2;
        sum+=val;
    }
    int res=prime(sum);
    if(res==1)
       P1 ;
    else
        P2;
    }
    return 0;
}

