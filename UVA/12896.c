#include<stdio.h>
///AC
int main() {
    int t,l;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&l);
        int a[l],b[l],i,j=0;
        char te[l+1];
        for(i=0; i<l; i++)
            scanf("%d",&a[i]);
        for(i=0; i<l; i++)
            scanf("%d",&b[i]);
        for(i=0; i<l; i++) {
            if(a[i]==0)
                te[j++]=' ';
            else if(a[i]==1) {
                if(b[i]==1)
                    te[j++]='.';
                else if(b[i]==2)
                    te[j++]=',';
                else if(b[i]==3)
                    te[j++]='?';
                else
                    te[j++]='"';
            } else if(a[i]==2) {
                if(b[i]==1)
                    te[j++]='a';
                else if(b[i]==2)
                    te[j++]='b';
                else
                    te[j++]='c';
            } else if(a[i]==3) {
                if(b[i]==1)
                    te[j++]='d';
                else if(b[i]==2)
                    te[j++]='e';
                else
                    te[j++]='f';
            } else if(a[i]==4) {
                if(b[i]==1)
                    te[j++]='g';
                else if(b[i]==2)
                    te[j++]='h';
                else
                    te[j++]='i';
            } else if(a[i]==5) {
                if(b[i]==1)
                    te[j++]='j';
                else if(b[i]==2)
                    te[j++]='k';
                else
                    te[j++]='l';
            } else if(a[i]==6) {
                if(b[i]==1)
                    te[j++]='m';
                else if(b[i]==2)
                    te[j++]='n';
                else
                    te[j++]='o';
            } else if(a[i]==7) {
                if(b[i]==1)
                    te[j++]='p';
                else if(b[i]==2)
                    te[j++]='q';
                else if(b[i]==3)
                    te[j++]='r';
                else
                    te[j++]='s';
            } else if(a[i]==8) {
                if(b[i]==1)
                    te[j++]='t';
                else if(b[i]==2)
                    te[j++]='u';
                else
                    te[j++]='v';
            } else if(a[i]==9) {
                if(b[i]==1)
                    te[j++]='w';
                else if(b[i]==2)
                    te[j++]='x';
                else if(b[i]==3)
                    te[j++]='y';
                else
                    te[j++]='z';
            }
        }
        te[l]='\0';
        printf("%s\n",te);
    }

    return 0;
}

