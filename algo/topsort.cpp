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
#define TC(t)       int t;cin>>t;while(t--)
#define line        '\n'
#define space       ' '
#define redian      180/PI
#define all(x)      x.begin(),x.end()
#define Sort(x)     sort(all(x))
#define mem(a,b)    memset(a,b,sizeof(a))
#define loopv(p,v)  for(auto p:(v))
#define loop(a,b,c) for(long long a=(b);a<(c);a++)
#define loopr(a,b,c)for(int a=(b);a>=(c);a--)
#define faster      ios_base::sync_with_stdio(0);cin.tie(0);

const int MOD=1073741824;
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
///by dfs
bool vis[N];
vi edge[N], topS;
void dfs_visit(int u)
{
    vis[u]=1;
    for(int i=0;i<(int)edge[u].size();i++){
        int v=edge[u][i];
        if(!vis[v])dfs_visit(v);
    }
    topS.pb(u);
}
void topsort(int node)
{
    mem(vis,0);
    for(int i=0;i<node;i++)
        if(!vis[i])dfs_visit(i);
    reverse(topS.begin(),topS.end());
}
///by indegree
vi edge[N];
int indeg[N],node;
void topsort()
{
    int i;
    for(i=1;i<=node;i++)
        if(indeg[i]==0)
        {
            indeg[i]=-1;
            break;
        }
    if(i==node+1) return;
    printf("%d ",i);
    for(int j=0;j<edge[i].size();j++)
        indeg[edge[i][j]]--;
    topsort();
}
int main()
{

}

