#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           31
#define pb          push_back
#define pp          pop_back
#define mk          make_pair
#define PI          acos(-1)
#define EPS         1e-9
#define INF         1<<20
#define TC(t)       int t;cin>>t;while(t--)
#define line        '\n'
#define space       ' '
#define redian      180/PI
#define all(x)      x.begin(),x.end()
#define Sort(x)     sort(all(x))
#define mem(a,b)    memset(a,b,sizeof(a))
#define loopv(p,v)  for(auto p:(v))
#define loop(a,b,c) for(int a=(b);a<(c);a++)
#define loopr(a,b,c)for(int a=(b);a>=(c);a--)
#define faster      ios_base::sync_with_stdio(0);cin.tie(0);

const int MOD=10;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<int,string> psi;
typedef map<int,string>mis;
typedef pair<int,pii>pi3;
inline bool sc(int &_x) {return scanf("%d",&_x)==1;}
inline bool sc(int &_x, int &_y) {return sc(_x)&&sc(_y);}
inline bool sc(int &_x, int &_y, int &_z) {return sc(_x)&&sc(_y)&&sc(_z);}
inline bool sc(int &_x, int &_y, int &_z, int &_zz) {return sc(_x)&&sc(_y)&&sc(_z)&&sc(_zz);}
/*      direction
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};
int kx[]={2,2,-2,-2,1,-1,1,-1};
int ky[]={1,-1,1,-1,2,2,-2,-2};*/
int x3[]={0,0,0,0,1,-1};
int y3[]={1,-1,0,0,0,0};
int z3[]={0,0,1,-1,0,0};
int l,r,c;
char grid[N][N][N];
bool vis[N][N][N];
int dis[N][N][N];
void bfs(int x,int y,int z)
{
    mem(vis,0);mem(dis,0);
    queue<pi3>q;
    q.push(mk(x,mk(y,z)));
    vis[x][y][z]=1;
    dis[x][y][z]=0;
    while(!q.empty())
    {
        pi3 u=q.front();q.pop();
        loop(i,0,6)
        {
            int nx=x3[i]+u.X;
            int ny=y3[i]+u.Y.X;
            int nz=z3[i]+u.Y.Y;
            if(nx>=0&&nx<l&&ny>=0&&ny<r&&nz>=0&&nz<c&& grid[nx][ny][nz]!='#'&& vis[nx][ny][nz]==0)
            {
                vis[nx][ny][nz]=1;
                dis[nx][ny][nz]=dis[u.X][u.Y.X][u.Y.Y]+1;
                q.push(mk(nx,mk(ny,nz)));
            }
        }
    }

}
int main()
{
    faster
    while(cin>>l>>r>>c &&l)
    {
        int ii,jj,kk,aa,bb,cc;
        loop(i,0,l)loop(j,0,r)loop(k,0,c)
        {
            cin>>grid[i][j][k];
            if(grid[i][j][k]=='S')ii=i,jj=j,kk=k;
            if(grid[i][j][k]=='E')aa=i,bb=j,cc=k;
        }
        bfs(ii,jj,kk);
        if(!vis[aa][bb][cc])cout<<"Trapped!\n";
        else cout<<"Escaped in "<<dis[aa][bb][cc]<<" minute(s).\n";
    }

}
