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
#define N           1000001
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
#define Sort(x)     sort(x.begin(),x.end())
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
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};  */
int a[N];
int quary(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=a[idx];
        idx-=idx &(-idx);
    }
    return sum;
}
void update(int idx,int x,int n)
{
    while(idx<=n)
    {
        a[idx]+=x;
        idx+=idx & (-idx);
    }

}
int main()
{
    for(int i=0;i<10;i++)
    {
        int x,n;
        cin>>n>>x;
        update(n,x,10);
    }
    for(int i=0;i<9;i++)
    {
        int n;
        cin>>n;
        cout<<n<<"->"<<quary(n)<<'\n';
    }
    return 0;
}
