#include <stdio.h>
#include<string.h>
#define C1 (a[0]=='o'&&a[1]=='n'&&a[2]=='e')
#define C2 (a[0]=='o'&&a[1]=='n')
#define C3 (a[0]=='o'&&a[2]=='e')
#define C4 (a[1]=='n'&&a[2]=='e')
///AC
int main()
{
    int t,len;
    char a[5];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        len=strlen(a);
        if(len==3)
        {
            if(C1||C2||C3||C4)
                printf("1\n");
            else
                printf("2\n");

        }
        else
            printf("3\n");
    }

    return 0;
}
