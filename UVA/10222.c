#include <stdio.h>
#include <ctype.h>
///AC
int main() {
    char text,c;
    while(scanf("%c",&text)==1) {

        if(text==' ')
            printf(" ");
        else if(text=='\n')
            printf("\n");
        else {
            c=tolower(text);

            if(c=='l')
                printf("j");
            else if(c=='k')
                printf("h");
            else if(c=='j')
                printf("g");
            else if(c=='h')
                printf("f");
            else if(c=='g')
                printf("d");
            else if(c=='f')
                printf("s");
            else if(c=='d')
                printf("a");
            else if(c=='"'||c=='\'')
                printf("l");
            else if(c==';'||c==':')
                printf("k");
            else if(c==']'||c=='}')
                printf("p");
            else if(c=='['||c=='{')
                printf("o");
            else if(c=='p')
                printf("i");
            else if(c=='o')
                printf("u");
            else if(c=='i')
                printf("y");
            else if(c=='u')
                printf("t");
            else if(c=='y')
                printf("r");
            else if(c=='t')
                printf("e");
            else if(c=='r')
                printf("w");
            else if(c=='e')
                printf("q");
            else if(c=='.'||c=='>')
                printf("m");
            else if(c==','||c=='<')
                printf("n");
            else if(c=='m')
                printf("b");
            else if(c=='n')
                printf("v");
            else if(c=='b')
                printf("c");
            else if(c=='v')
                printf("x");
            else if(c=='c')
                printf("z");

        }
    }


    return 0;
}

