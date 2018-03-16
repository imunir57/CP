#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           100015
#define pb          push_back
#define pp          pop_back
#define mk          make_pair
#define PI          acos(-1)
#define EPS         1e-9
#define INF         1<<29
#define ln          '\n'
#define sp          ' '
#define redian      180/PI
#define all(x)      x.begin(),x.end()
#define Sort(x)     sort(all(x))
#define mem(a,b)    memset(a,b,sizeof(a))
#define lpa(p,v)    for(auto p:(v))
#define lp(a,b,c)   for(int a=(b);a<(c);a++)
#define lp0(a,n)    lp(a,0,n)
#define lpr(a,b,c)  for(int a=(b);a>=(c);a--)
#define faster      ios_base::sync_with_stdio(0);cin.tie(0);

const int MOD=1e8+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;
typedef pair<int,string> psi;
typedef map<int,int>mii;
inline bool sc(int &_x){return scanf("%d",&_x)==1;}
inline bool sc(int &_x, int &_y){return sc(_x)&&sc(_y);}
inline bool sc(int &_x, int &_y, int &_z){return sc(_x)&&sc(_y)&&sc(_z);}
inline bool sc(int &_x, int &_y, int &_z, int &_zz){return sc(_x)&&sc(_y)&&sc(_z)&&sc(_zz);}
/*
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};
int kx[]= {2,2,-2,-2,1,-1,1,-1};
int ky[]= {1,-1,1,-1,2,2,-2,-2};  */
int n;
int dp[101][1001];
int weight[1001], cost[101];
int cap;
int func(int i,int w)
{
    if(i==n+1)return 0;
    if(dp[i][w]!=-1)return dp[i][w];
    int prof1=0,prof2=0;
    if(w+weight[i]<=cap)
        prof1=cost[i]+func(i+1,w+weight[i]);
    prof2=func(i+1,w);
    dp[i][w]=max(prof1,prof2);
    return dp[i][w];
}
int main()
{
    cin>>n;
    lp(i,1,n+1)cin>>weight[i]>>cost[i];
    mem(dp,-1);
    cin>>cap;
    cout<<func(1,0);

}

