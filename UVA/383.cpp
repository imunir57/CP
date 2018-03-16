#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           32
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
typedef map<int,int>mii;
inline bool sc(int &_x) {
    return scanf("%d",&_x)==1;
}
inline bool sc(int &_x, int &_y) {
    return sc(_x)&&sc(_y) ;
}
inline bool sc(int &_x, int &_y, int &_z) {
    return sc(_x)&&sc(_y)&&sc(_z) ;
}
inline bool sc(int &_x, int &_y, int &_z, int &_zz) {
    return sc(_x)&&sc(_y)&&sc(_z)&&sc(_zz) ;
}
/*      direction
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};
int kx[]={2,2,-2,-2,1,-1,1,-1};
int ky[]={1,-1,1,-1,2,2,-2,-2};*/
int a[N][N],n;
void floyd()
{
    loop(k,0,n)loop(i,0,n)loop(j,0,n)
    {
        if(i!=j)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    }
}
int main()
{
    faster
    int t,cs=0;cin>>t;
    cout<<"SHIPPING ROUTES OUTPUT\n";
    while(t--)
    {
        int m,p;cin>>n>>m>>p;
        map<string,int>mp;
        map<int,string>mp1;
        loop(i,0,n)
        {
            string s;cin>>s;
            mp[s]=i;
            mp1[i]=s;
        }
        loop(i,0,N)loop(j,0,N)a[i][j]=INF;
        loop(i,0,m)
        {
            string u,v;cin>>u>>v;
            a[mp[u]][mp[v]]=a[mp[v]][mp[u]]=1;
        }
        floyd();
        cout<<"\nDATA SET  "<<++cs<<"\n\n";
        loop(i,0,p)
        {
            int x;
            string u,v;cin>>x>>u>>v;
            int y=mp[u],z=mp[v];
            if(a[y][z]==INF)cout<<"NO SHIPMENT POSSIBLE\n";
            else cout<<'$'<<x*100*a[y][z]<<line;
        }

    }
    cout<<"\nEND OF OUTPUT\n";
}
