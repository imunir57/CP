#include<stdio.h>
#define C1 text[i]>='a'&&text[i]<='o'
#define C2 text[i]>='p'&&text[i]<='s'
#define C3 text[i]>='t'&&text[i]<='v'
#define C4 text[i]>='w'&&text[i]<='z'
#define C5 text[i]==' '
#define P1 printf("Case #%d: %d\n",tc,cnt)
///AC
int main() {
    int t,tc=0;
    char text[101];
    scanf("%d",&t);
    getchar();
    while(t--) {
        tc++;
        int i,a,cnt=0;
        gets(text);
        for(i=0; text[i]!='\0'; i++) {
            if(C1) {
                a=text[i]%3;
                if(a==0)
                    a=3;
                cnt+=a;
            } else if(C2) {
                a=text[i]%4+1;
                cnt+=a;
            } else if(C3) {
                a=text[i]%5;
                cnt+=a;
            } else if(C4) {
                if(text[i]=='w')
                    a=1;
                else if(text[i]=='x')
                    a=2;
                else if(text[i]=='y')
                    a=3;
                else
                    a=4;
                cnt+=a;
            } else if(C5)
                cnt++;

        }
        P1;
    }
    return 0;
}

