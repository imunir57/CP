#include<stdio.h>
#include<string.h>
#define uul unsigned long long int
///AC
 uul fact(int l)
{
    int i;
    uul f=1;
    for(i=l;i>1;i--)
        f*=i;
    return f;
}

int main()
{
    char w[21];
    int t,l,tc=0;
    uul ans;
    scanf("%d",&t);
    while(t--)
    {
        int i,a[26]={};
        uul df=1;
        tc++;
        scanf("%s",w);
        l=strlen(w);
        for(i=0;i<l;i++)
            a[w[i]-'A']++;
        for(i=0;i<26;i++){
            if(a[i]!=0 || a[i]!=1)
            df*=fact(a[i]);
        }
        ans=fact(l)/df;
        printf("Data set %d: %llu\n",tc,ans);

    }
}

