#include<stdio.h>
#define C1 a[0]>a[1]&&a[1]>a[2]&&a[2]>a[3]&&a[3]>a[4]&&a[4]>a[5]&&a[5]>a[6]&&a[6]>a[7]&&a[7]>a[8]&&a[8]>a[9]
#define C2 a[0]<a[1]&&a[1]<a[2]&&a[2]<a[3]&&a[3]<a[4]&&a[4]<a[5]&&a[5]<a[6]&&a[6]<a[7]&&a[7]<a[8]&&a[8]<a[9]

///AC

int main() {
    int t;
    scanf("%d",&t);
    printf("Lumberjacks:\n");
    while(t--) {
        int a[10],i;

        for(i=0; i<10; i++)
            scanf("%d",a+i);

        if(C1||C2)
            printf("Ordered\n");
        else
            printf("Unordered\n");

    }



}

