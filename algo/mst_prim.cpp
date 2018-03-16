#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           41
#define pb          push_back
#define pp          pop_back
#define mk          make_pair
#define PI          acos(-1)
#define EPS         1e-9
#define INF         1<<30
#define TC(t)       int t;cin>>t;while(t--)
#define line        '\n'
#define space       ' '
#define redian      180/PI
#define Sort(x)     sort(x.begin(),x.end())
#define mem(a,b)    memset(a,b,sizeof(a))
#define loopv(p,v)  for(auto p:(v))
#define loop(a,b,c) for(int a=(b);a<(c);a++)
#define loopr(a,b,c)for(int a=(b);a>=(c);a--)
#define faster      ios_base::sync_with_stdio(0);cin.tie(0);

const int MOD=1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<char,int> pci;
//      direction
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};
int kx[]={2,2,-2,-2,1,-1,1,-1};
int ky[]={1,-1,1,-1,2,2,-2,-2};
vector<pii>e[N];
bool vis[N];
int prims()
{
    priority_queue<pii>p;
    p.push(mk(0,1));
    int mst_cost=0;
    while(!p.empty())
    {
        pii t=p.top();p.pop();
        int node=t.Y,cost=-t.X;
        if(vis[node])continue;
        mst_cost+=cost;
        vis[node]=1;
        for(int i=0;i<e[node].size();i++)
        {
            pii u=e[node][i];
            if(!vis[u.Y])p.push(mk(-u.X,u.Y));
        }
    }
    return mst_cost;
}
int main()
{
    int n,edg;cin>>n>>edg;
    for(int i=0;i<edg;i++)
    {
        int x,y,w;cin>>x>>y>>w;
        e[x].pb(mk(w,y));
        e[y].pb(mk(w,x));
    }
    cout<<prims();
     return 0;
}
