#include <stdio.h>

int main()
{
    int i=0;
    char text;
    while(scanf("%c",&text)==1)
    {
        if(text=='"')
        {
            if(i%2==0)
            {
                printf("``");
                i++;
            }
            else
            {
                printf("''");
                i++;
            }
        }
        else
        {
            printf("%c",text);
        }
    }


    return 0;
}
