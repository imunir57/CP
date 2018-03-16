#include<stdio.h>
#define CLO (c*60+d)-(a*60+b)
///AC
int main()
{
    int a,b,c,d,ans;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)==4)
    {
        if(a==0&&b==0&&c==0&&d==0)
            break;
        CLO;
        if(CLO<0)
            ans=CLO+1440;
        else
            ans=CLO;
        printf("%d\n",ans);
    }
}

