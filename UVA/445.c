#include <stdio.h>
///AC
int main()
{
    char text;
    int x=0,i;
    while(scanf("%c",&text)==1){

        if(text=='\n'||text=='!')
            printf("\n");
        else if(text>='1'&&text<='9')
            x+=text-'0';


        else

        {
            if(text=='b')
            {
                for(i=0;i<x;i++)
                    printf(" ");
                    x=0;
            }
            else
            {
                for(i=0;i<x;i++)
                    printf("%c",text);
                x=0;
            }
        }

    }

    return 0;
}
