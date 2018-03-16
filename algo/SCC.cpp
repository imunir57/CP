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
#include<unordered_set>
#include<map>
#include<utility>
#include<list>
#include<sstream>
using namespace std;
#define X           first
#define Y           second
#define N           102
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
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<char,int> pci;
/*      direction
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};
int kx[]={2,2,-2,-2,1,-1,1,-1};
int ky[]={1,-1,1,-1,2,2,-2,-2};*/
vi e[N],dfs_num,dfs_low,s,visited;

int c,scc;
void tarjanSCC(int u)
{
    dfs_low[u]=dfs_num[u]=c++;
    s.pb(u);
    visited[u]=1;
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i];
        if(!dfs_num[v])tarjanSCC(v);
        if(visited[v])dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_low[u]==dfs_num[u])
    {
        cout<<"SCC "<<++scc<<'\n';
        while(1)
        {
            int v=s.back();s.pop_back();visited[v]=0;
            cout<<' '<<v<<'\n';
            if(u==v)break;
        }
        cout<<'\n';
    }

}
int main() {
    int n,edg;cin>>n>>edg;
    for(int i=0;i<edg;i++)
    {
        int x,y;cin>>x>>y;
        e[x].pb(y);
    }
    dfs_num.assign(N,0),dfs_low.assign(N,0),visited.assign(N,0);
    scc=c=0;
    for(int i=0;i<n;i++)
        if(!dfs_num[i])tarjanSCC(i);

    return 0;
    }
