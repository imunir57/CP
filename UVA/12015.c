#include<stdio.h>
#include<string.h>
///AC
int max,i,j,tc=0;
char top[10][101];

struct web {
    char url[101];
    int rate;
} site[10];

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        for(i=0; i<10; i++)
            scanf("%s %d",site[i].url,&site[i].rate);
            max=0;
        for(i=0; i<10; i++) {
            if(site[i].rate>max)
                max=site[i].rate;
        }
        int j=0;
        tc++;
        for(i=0; i<10; i++) {
            if(site[i].rate>=max) {
                strcpy(top[j++],site[i].url);

            }
        }
        printf("Case #%d:\n",tc);
        for(i=0; i<j; i++)
            printf("%s\n",top[i]);

    }


    return 0;
}

