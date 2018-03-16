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
#define N           100005
#define pb          push_back
#define pp          pop_back
#define mk          make_pair
#define PI          acos(-1)
#define EPS         1e-9
#define INF         1<<30
#define TC(t)       cin>>t;while(t--)
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

int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};
bool visited[N];
int dist[N];
vi adj[N];
queue<int>q;
void bfs(int root)  ///1d bfs
{
    q.push(root);
    dist[root]=0;
    visited[root]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(auto i:adj[t])
        {
            if(!visited[i])
            {
                visited[i]=1;
                q.push(i);
                dist[i]=dist[t]+1;
            }
        }
    }

}
queue<pii>qi;
bool vis[100][100];
int dis[100][100];
void bfs(int x,int y)   ///2d bfs / floodfill
{
    qi.push(mk(x,y));
    vis[x][y]=1;
    dis[x][y]=0;
    while(!qi.empty())
    {
        pii t=qi.front();
        qi.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x4[i]+t.X;
            int ny=y4[i]+t.Y;
            if(!vis[nx][ny])
            {
                vis[nx][ny]=1;
                dis[nx][ny]=dis[t.X][t.Y]+1;
                qi.push(mk(nx,ny));
            }
        }
    }

}
int main()
{
    for(int i=0;i<10;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bfs(1);

    return 0;
}
