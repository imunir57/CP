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
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<utility>
#include<list>
using namespace std;
#define cube(x)     (x)*(x)*(x)
#define X           first
#define Y           second
#define N           10002
#define pb          push_back
#define pp          pop_back
#define mk          make_pair
#define PI          acos(-1)
#define EPS         1e-9
#define TC(t)       scanf("%d",&t);while(t--)
#define line        '\n'
#define space       ' '
#define redian      180/PI
#define Sort(x)     sort(x.begin(),x.end())
#define mem(a,b)    memset(a,b,sizeof(a))
#define loopv(p,v)  for(auto p:(v))
#define loop(a,b,c) for(int a=(b);a<(c);a++)
#define loopr(a,b,c)for(int a=(b);a>=(c);a--)

const int MOD=1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

//      direction
int x4[]={1,-1,0,0};
int y4[]={0,0,1,-1};
int x8[]={0,0,+1,-1,-1,+1,-1,+1};
int y8[]={-1,+1,0,0,+1,+1,-1,-1};

int coin[21];
int make;
ll dp[22][N];

ll call(int i,int amount)
{
    if(i>=21)
    {
        if(!amount)return 1;
        return 0;
    }
    if(dp[i][amount]!=-1)return dp[i][amount];
    ll ret1=0,ret2=0;
    if(amount-coin[i]>=0)ret1=call(i,amount-coin[i]);
    ret2=call(i+1,amount);
    return dp[i][amount]=ret1+ret2;
}
int main()
{
    loop(i,0,21)coin[i]=cube(i+1);
    mem(dp,-1);
    while(scanf("%d",&make)==1)
    {
        printf("%lld\n",call(0,make));
    }
    return 0;
}
