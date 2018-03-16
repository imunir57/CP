#include<stdio.h>
#include<string.h>
///AC
int main() {

    int a[100],i=0;
    char c[10];
    while(scanf("%d",&a[i])==1) {
        if(a[i]==0)
            break;
        int j=0,k=0,hi[100],lo[100],l,h,z;
        while(1) {
            gets(c);


            if(!strcmp(c,"right on")) {
                z=a[i];
                break;
            }

            else if(!strcmp(c,"too high"))
                hi[j++]=a[i++];
            else if(!strcmp(c,"too low"))
                lo[k++]=a[i++];

            scanf("%d",&a[i]);
        }


        for(h=0; h<j; h++) {
            if(hi[h]<=z)
                break;
        }
        for(l=0; l<k; l++) {
            if(lo[l]>=z)
                break;
        }
        if(h==j&&l==k)
            printf("Stan may be honest\n");
        else
            printf("Stan is dishonest\n");
        i=0;
    }
}

