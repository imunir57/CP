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
int a[N],bucket[444];
int rt;
void build(int n)
{
    rt=ceil(sqrt(n));
    for(int i=0;i<n;i++)
        bucket[i/rt]+=a[i];
}
void update(int p,int v)
{
    bucket[p/rt]+=v-a[p];
    a[p]=v;
}
int query(int l,int r)
{
    int sum=0;
    int st=l/rt,en=r/rt;
    for(int i=l;i<(st+1)*rt;i++)
        sum+=a[i];
    for(int i=en*rt;i<r+1;i++)
        sum+=a[i];
    for(int i=st+1;i<en;i++)
        sum+=bucket[i];
    return sum;
}
int main()
{
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>a[i];
    build(n);
    lp0(i,rt)cout<<bucket[i]<<sp;cout<<ln;
    while(q--)
    {
        int x,l,r;cin>>x>>l>>r;
        if(x==1)    //1 update
            update(l,r);
        else        //2 query
            cout<<query(l,r)<<'\n';
    }
    return 0;
}
/*
7 6
5 2 1 9 3 6 4
2 0 6
2 2 4
1 3 5
2 2 6
1 5 2
2 0 6
*/
