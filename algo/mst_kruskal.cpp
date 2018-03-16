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
typedef vector<ll> vi;
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
vector<pair<int,pii> > edge;
int parent[N];
int find(int r)
{
    if(parent[r]==r)return r;
    return find(parent[r]);
}
int kruskal(int n)
{
    sort(all(edge));
    for(int i=0;i<n;i++) parent[i]=i;
    int c=0,s=0;
    for(auto i:edge)
    {
        int u=find(i.Y.X);
        int v=find(i.Y.Y);
        if(u!=v)
        {
            s+=i.X;
            c++;
            parent[u]=v;
            if(c==n-1)break;
        }
    }
    return s;
}
int main()
{
    int n,edg;cin>>n>>edg;
    for(int i=0;i<edg;i++)
    {
        int x,y,w;cin>>x>>y>>w;
        edge.pb(mk(w,mk(x,y)));
    }
    cout<<kruskal(n);
}




