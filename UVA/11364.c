#include <stdio.h>
///AC
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,i,j;
        scanf("%d",&n);
        int a[n];
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<n; i++) {
            for(j=i+1; j<n; j++) {
                if(a[i]<a[j]) {
                    a[i]=a[i]^a[j];
                    a[j]=a[i]^a[j];
                    a[i]=a[i]^a[j];

                }
            }
        }

        int sum=0;
        for(i=0; i<n-1; i++)
            sum+=a[i]-a[i+1];

        sum+=a[0]-a[n-1];
        printf("%d\n",sum);
    }

    return 0;
}

