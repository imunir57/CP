#include <stdio.h>

int main()
{
    int n,t,b,w,a,c,m,i,j=0;
    char s[12];
    scanf("%d",&c);
    while(c--)
    {
        t=b=w=a=0;
        j++;
        scanf("%d",&m);
        scanf("%s",s);
        for(i=0; i<m; i++)
        {

            if(s[i]=='B')
                b++;
            else if(s[i]=='W')
                w++;
            else if(s[i]=='A')
                a++;
            else if(s[i]=='T')
                t++;

        }
        if(a==m)
            printf("Case %d: ABANDONED\n",j);
        else if(b==w)
            printf("Case %d: DRAW %d %d\n",j,w,t);
        else if((b==m||b!=m)&&w==0&&t==0&&a!=m)
            printf("Case %d: BANGLAWASH\n",j);
        else if((w==m||w!=m)&&b==0&&t==0&&a!=m)
            printf("Case %d: WHITEWASH\n",j);
        else if(b>w)
            printf("Case %d: BANGLADESH %d - %d\n",j,b,w);
        else if(b<w)
            printf("Case %d: WWW %d - %d\n",j,w,b);




}
return 0;
}



