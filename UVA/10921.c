#include <stdio.h>
#define A1 c=='A'||c=='B'||c=='C'
#define A2 c=='D'||c=='E'||c=='F'
#define A3 c=='G'||c=='H'||c=='I'
#define A4 c=='J'||c=='K'||c=='L'
#define A5 c=='M'||c=='N'||c=='O'
#define A6 c=='P'||c=='Q'||c=='R'||c=='S'
#define A7 c=='T'||c=='U'||c=='V'
#define A8 c=='W'||c=='X'||c=='Y'||c=='Z'

int main() {

    char c;
    while(scanf("%c",&c)==1) {
            if(c=='\n')
            printf("\n");
        else if(A1)
            printf("2");
        else if(A2)
            printf("3");
        else if(A3)
            printf("4");
        else if(A4)
            printf("5");
        else if(A5)
            printf("6");
        else if(A6)
            printf("7");
        else if(A7)
            printf("8");
        else if(A8)
            printf("9");
        else
            printf("%c",c);
    }


    return 0;
}

