#include<stdio.h>
///AC

int main() {

    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned long long int a,b,c,d;
        scanf("%llu%llu%llu%llu",&a,&b,&c,&d);

        if(a==b&&b==c&&c==d)
            printf("square\n");
        else if(a+b==c+d||a+d==b+c||a+c==b+d)
            printf("rectangle\n");
        else if(a+b+c>d&&a+b+d>c&&a+d+c>b&&d+b+c>a)
            printf("quadrangle\n");
        else
            printf("banana\n");
    }
}

