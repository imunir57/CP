#include <stdio.h>
#include <math.h>
///AC
int main() {

    int root,n,c,m;
    while(scanf("%d%d",&n,&m)==2) {
        if(n==0&&m==0)
            break;
        c=0;
        for(; n<=m; n++) {
            if(n%10==2||n%10==3||n%10==7||n%10==8)
                continue;
            root=sqrt(n);
            root*=root;
            if(root==n)
                c++;
        }
        printf("%d\n",c);
    }
    return 0;
}

