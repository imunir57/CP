#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           200001
#define pb          push_back
#define pp          pop_back
#define mk          make_pair
#define PI          acos(-1)
#define EPS         1e-9
#define INF         1<<25
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
#define debug(a)    cout<<a<<ln;
#define debug1(a,b)    cout<<a<<sp<<b<<ln;

const int MOD=100000007;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
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
int ways[10005];
int coin[105];
int n;
int solve(int make)
{
    ways[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=coin[i];j<=make;j++)
        {
            ways[j]=(ways[j]%MOD+ways[j-coin[i]]%MOD)%MOD;
        }
    }
    return ways[make];
}

int main()
{
    faster
    int t,make,cs=0;cin>>t;
    while(t--){
        cin>>n>>make;
        lp0(i,n)cin>>coin[i];
        mem(ways,0);
        cout<<"Case "<<++cs<<": "<<solve(make)<<ln;
    }
}



