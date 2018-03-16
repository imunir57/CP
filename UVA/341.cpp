#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           11
#define pb          push_back
#define pp          pop_back
#define mk          make_pair
#define PI          acos(-1)
#define EPS         1e-9
#define INF         1<<28
#define TC(t)       int t;cin>>t;while(t--)
#define line        '\n'
#define space       ' '
#define redian      180/PI
#define all(x)      x.begin(),x.end()
#define For0(a,n)   for(int a=1;a<=(n);a++)
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
int a[N][N],p[N][N],n;
void floyd()
{
    For0(i,n)For0(j,n)p[i][j]=i;
    For0(k,n)For0(i,n)For0(j,n)
    {
        if(a[i][j]>a[i][k]+a[k][j])
        {
            a[i][j]=a[i][k]+a[k][j];
            p[i][j]=p[k][j];
        }
    }
}
void path(int i,int j)
{
    if(i!=j)path(i,p[i][j]);
    cout<<space<<j;
}
int main() {
    int cs=0;
    faster
    while(cin>>n && n)
    {
        For0(i,n)For0(j,n)a[i][j]=INF;
        For0(i,n)
        {
            int x;cin>>x;
            loop(j,0,x)
            {
                int c,d;cin>>c>>d;
                a[i][c]=d;
            }
        }
        int q,w;cin>>q>>w;
        floyd();
        cout<<"Case "<<++cs<<": Path =";
        path(q,w);
        cout<<"; "<<a[q][w]<<" second delay\n";
    }
    return 0;
    }
