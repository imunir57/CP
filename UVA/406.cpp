/*************************************************************************

    #       #             #      #   *
    # *   * #             # *    #
    #  * *  #   #     #   #  *   #   #   #####
    #   *   #   #     #   #   *  #   #   #  **
    #       #   #     #   #    * #   #   #
    #       #   #######   #      #   #   #

*************************************************************************/
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<utility>
#include<list>

#define loop(a,b,c) for(int a=b;a<c;a++)
#define EPS 1e-7
#define redian acos(-1)/180
#define TC(t) scanf("%d",&t);while(t--)
#define SIZE 1001
#define space ' '
#define line '\n'

typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

bool prim[SIZE];
void seive()
{
	LL i,j;

    for(i=2; i<=sqrt(SIZE); i++) {
        if(prim[i]==0) {
            for(j=2*i; j<=SIZE; j+=i)
                prim[j]=1;
        }
    }
}

int main() {

    int n,c,i;
    seive();
    while(scanf("%d %d",&n,&c)==2){
    int j=0,ans[n];
    for(int i=1;i<=n;i++)
    {
        if(prim[i]==0)
        {
            ans[j++]=i;
        }
    }
    printf("%d %d:",n,c);
    if(j<c*2)
    {
        for(i=0;i<j;i++)
            printf(" %d",ans[i]);
    }
    else if(j&1)
    {
        for(i=j/2-c+1;i<=j/2+c-1;i++)
            printf(" %d",ans[i]);
    }
    else
    {
        for(i=j/2-c;i<j/2+c;i++)
            printf(" %d",ans[i]);
    }
    printf("\n\n");
    }
    return 0;
}