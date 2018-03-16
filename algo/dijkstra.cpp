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
#define X           first
#define Y           second
#define N           100001
#define pb          push_back
#define pp          pop_back
#define mk          make_pair
#define PI          acos(-1)
#define EPS         1e-9
#define INF         1<<30
#define TC(t)       scanf("%d",&t);while(t--)
#define line        '\n'
#define space       ' '
#define redian      180/PI
#define Sort(x)     sort(x.begin(),x.end(),greater<char>())
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
/*      direction
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};*/
int par[N],dist[N];
vi adj[N],cost[N];
int n,m,s,d;
void dijkstra(int n)
{
    for(int i=0;i<n;i++)par[i]=dist[i]=-1;

    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push(mk(0,s));
    dist[s]=0;
    while(!q.empty())
        {
            pii t=q.top();
            q.pop();
            int u=t.Y;
            for(int i=0; i<adj[u].size(); i++)
                {
                    int v=adj[u][i];
                    if(dist[u]+cost[u][i]<dist[v]||dist[v]==-1)
                        {
                            dist[v]=dist[u]+cost[u][i];
                            par[v]=u;
                            q.push(mk(dist[v],v));
                        }
                }
        }
}

int main()
{

    return 0;
}
