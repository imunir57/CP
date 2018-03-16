#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           20000010
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
typedef pair<ll,ll> pii;
typedef pair<int,string> psi;
typedef map<int,int>mii;
/*      direction
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};
int kx[]={2,2,-2,-2,1,-1,1,-1};
int ky[]={1,-1,1,-1,2,2,-2,-2};*/

class contest {
    public:
        int pid[10],ac,pt;
        int id;
        bool check[10];
        contest() {mem(pid,0);id=ac=pt=0;mem(check,0);}
        bool operator<(const contest &rh) {
            if(ac==rh.ac){
            	if(pt==rh.pt)
            		return id<rh.id;
            return pt<rh.pt;
            }
            return ac>rh.ac;
        }
    };

int main() {
    int t,cs=0;
    cin>>t;
    getchar();
    getchar();
    while(t--) {
        if(cs)cout<<line;
        cs++;
        contest x[101];
        int a,b,c;
        char d;
        string s;
        while(getline(cin,s)) {
            if(s=="")break;
            stringstream ss(s);
            ss>>a>>b>>c>>d;
          //  cout<<a<<space<<b<<space<<c<<space<<d<<line;
            x[a].id=a;
            if(!x[a].check[b]) {
                if(d=='C') {
                    x[a].check[b]=1;
                    x[a].pid[b]+=c;
                    x[a].ac++;
                    x[a].pt+=x[a].pid[b];
                    }
                else if(d=='I') {
                    x[a].pid[b]+=20;
                    }
                }
            }
        sort(x+1,x+101);
        loop(i,0,101)if(x[i].id)
            cout<<x[i].id<<space<<x[i].ac<<space<<x[i].pt<<line;
        
        }
    return 0;
    }