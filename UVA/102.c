#include<stdio.h>
#define SUM b1+g1+c1+b2+g2+c2+b3+g3+c3+1
///AC
int main() {
    int b1,g1,c1,b2,g2,c2,b3,g3,c3;

    while(scanf("%d%d%d%d%d%d%d%d%d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)==9) {
        long long int a[6],i,min=SUM,c;
        char id[6][4]= {"BCG","BGC","CBG","CGB","GBC","GCB"};

        a[0]=b2+b3+g2+g1+c1+c3;
        a[1]=b2+b3+g1+g3+c1+c2;
        a[2]=b3+b1+g1+g2+c3+c2;
        a[3]=b1+b2+g1+g3+c3+c2;
        a[4]=b1+b3+g2+g3+c1+c2;
        a[5]=b2+b1+g3+g2+c1+c3;
        for(i=0; i<6; i++) {
            if(a[i]<min) {
                min=a[i];
                c=i;
            }
        }
        printf("%s %lld\n",id[c],min);
    }
}

