#include<stdio.h>
#include<string.h>
int main()
{///AC
    int t;
    scanf("%d",&t);
    while(t--){
    char score[81];
    int i,l,cnt=0,ans=0;
    scanf("%s",score);
    l=strlen(score);
    for(i=0;i<l;i++)
    {
        if(score[i]=='O')
            cnt++;
        else if(score[i]=='X')
            cnt=0;
        ans+=cnt;

    }
    printf("%d\n",ans);
    }
}

