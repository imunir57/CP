#include <stdio.h>

int main()
{
    char text;
    while(scanf("%c",&text)==1){

        if(text=='\n')
            printf("\n");
        else{
        text=text-7;
        printf("%c",text);
    }
    }


    return 0;
}
