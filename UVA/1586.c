#include<stdio.h>
#include<string.h>
#define Car 12.01
#define Hid 1.008
#define Oxy 16.00
#define Nit 14.010
#define C1 (com[i+1]-'0')*10+com[i+2]-'0'
#define C2 upd*(com[i+1]-'0')
///AC
int main() {
    int l,i,b,t;
    scanf("%d",&t);
    while(t--){
    char com[81];
    scanf("%s",com);
    l=strlen(com);
    double ans,upd,fans=0;
    for(i=0; i<l; i++) {
        if(com[i]=='C')
            upd=Car;
        else if(com[i]=='H')
            upd=Hid;
        else if(com[i]=='N')
            upd=Nit;
        else if(com[i]=='O')
            upd=Oxy;
        if(com[i+1]>='0'&&com[i+1]<='9') {
            if(com[i+2]>='0'&&com[i+2]<='9') {
                b=C1;
                ans=upd*b;
                i+=2;
            } else {
                ans=C2;
                i++;
            }
        } else
            ans=upd;
        fans+=ans;
    }
    printf("%.3lf\n",fans);
    }
}

