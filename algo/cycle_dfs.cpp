#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           100005
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

const int MOD=1e9+7;
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
/*      direction
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};
int kx[]={2,2,-2,-2,1,-1,1,-1};
int ky[]={1,-1,1,-1,2,2,-2,-2};*/
bool black[N],white[N],gray[N];
vi adj[N];
bool has_cycle(int u)
{
    gray[u]=1,white[u]=0;
    for(auto i:adj[u])
    {
        if(black[i])continue;
        if(gray[i])return true;
        if(has_cycle(i))
            return true;
    }
    gray[u]=0,black[u]=1;
    return false;
}
int main()
{
    faster
    int n,e;cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].pb(v);
    }
    for(int i=0;i<n;i++)white[i]=1;
    for(int i=0;i<n;i++)
    {
        if(white[i])
        {
            if(has_cycle(i)){cout<<"cycle found";break;}
        }
    }

}
/*
6 6
1 2
2 3
4 5
5 6
6 4
4 1
*/
