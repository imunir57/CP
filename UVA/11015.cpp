#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           23
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
int a[N][N],n,m;
void floyd() {
    loop(k,0,n)loop(i,0,n)loop(j,0,n) {
        if(i==j)continue;
        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        }
    }
int f() {
    int mn=INF,k=0;
    loop(i,0,n) {
        int s=0;
        loop(j,0,n)
        {
            if(a[i][j]!=INF)s+=a[i][j];
         //   cout<<a[i][j]<<line;
        }if(mn>s)
            mn=s,k=i;
        }
    return k;
    }
int main() {
    faster
    int cs=0;
    while(cin>>n>>m) {
    	if(n==0&&m==0)break;
        loop(i,0,N)loop(j,0,N)a[i][j]=INF;
        map<int,string>mp;
        loop(i,0,n) {
            string x;
            cin>>x;
            mp[i]=x;
            }
        loop(i,0,m) {
            int x,y,z;
            cin>>x>>y>>z;
            x--,y--;
            a[x][y]=a[y][x]=z;
            }
   //     loop(i,1,n+1)loop(j,1,n+1)cout<<a[i][j]<<space;
        floyd();
       // loop(i,0,n)loop(j,0,n)cout<<a[i][j]<<space;
        cout<<"Case #"<<++cs<<" : "<<mp[f()]<<line;
        }
    return 0;
    }
