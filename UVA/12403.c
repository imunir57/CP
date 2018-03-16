#include <stdio.h>
#include<string.h>
///AC
int main() {
    int t,tk;
    long long int total=0;
    char a[8];
    scanf("%d",&t);
    while(t--) {
        scanf("%s",a);
        if(!strcmp(a,"donate")) {
            scanf("%d",&tk);
            total+=tk;
        } else  if(!strcmp(a,"report"))
            printf("%lld\n",total);
    }
    return 0;
}

