#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           101
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

const int MOD=1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<int,string> psi;
typedef map<int,int>mii;
/*      direction
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};
int kx[]={2,2,-2,-2,1,-1,1,-1};
int ky[]={1,-1,1,-1,2,2,-2,-2};*/
int a[N][N];
void floyd()
{
    loop(k,1,N)loop(i,1,N)loop(j,1,N)
            {if(i==j)continue;
            a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
}
double f()
{
    int s=0,sum=0;
    loop(i,1,N)loop(j,1,N)
        if(a[i][j]!=INF) s++,sum+=a[i][j];
    return (double)sum/s;
}
int main()
{
    faster
    int n,m,cs=0;
    while(cin>>n>>m &&n&&m)
    {
        loop(i,0,N)loop(j,0,N)a[i][j]=INF;
        a[n][m]=1;
        while(cin>>n>>m &&n&&m)
            a[n][m]=1;
        floyd();
        cout<<"Case "<<++cs<<": average length between pages = "<<fixed<<setprecision(3)<<f()<<" clicks\n";
    }
    return 0;
}
