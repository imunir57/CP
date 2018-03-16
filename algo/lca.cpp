#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           100004
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
int lev[N],par[N],table[N][25];
vi adj[N];
void dfs(int s,int u,int dep)
{
    par[u]=s;
    lev[u]=dep;
    for(auto i: adj[u])
    {
        if(i==s)continue;
        dfs(u,i,dep+1);
    }
}
int lca_query(int u,int v)
{
    if(lev[u]<lev[v])
        swap(u,v);
    int log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>lev[u])break;
        log++;
    }
    for(int i=log;i>=0;i--)
        if(lev[u]-(1<<i)>=lev[v])
            u=table[u][i];
    if(u==v)return u;

    for(int i=log;i>=0;i--)
        if(table[u][i]!=-1 && table[u][i]!=table[v][i])
            u=table[u][i],v=table[v][i];
    return par[u];
}
void lca_init(int n)
{
    mem(table,-1);
    for(int i=0;i<n;i++)
        table[i][0]=par[i];
    for(int j=1;(1<<j)<n;j++)
        for(int i=0;i<n;i++)
            if(table[i][j-1]!=-1)
                table[i][j]=table[table[i][j-1]][j-1];
}
int main()
{
    int n;cin>>n;
    lp0(i,n-1)
    {
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int q;cin>>q;
    dfs(0,1,0);
    lca_init(n+1);
    while(q--)
    {
        int u,v;cin>>u>>v;
        cout<<lca_query(u,v)<<ln;
    }

	return 0;
}
