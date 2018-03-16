#include <stdio.h>
#include<string.h>
#define S !strcmp(s,"Hajj")
#define P1 printf("Case %d: Hajj-e-Akbar\n",c)
#define P2 printf("Case %d: Hajj-e-Asghar\n",c)
int main()
{
    int c=1;
    char s[300];
    while(scanf("%s",s)==1){

            if(s[0]=='*')
                break;

    if(S)
        P1;
    else
        P2;

    c++;
    }
    return 0;
}



