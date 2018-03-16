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
int a[N],tree[N*4],n;
void build(int p=1,int l=1,int r=n)
{
    if(l==r)tree[p]=a[l];
    else
    {
        int m=(l+r)/2,left=p*2,right=left+1;
        build(left,l,m);
        build(right,m+1,r);
        tree[p]=tree[left]+tree[right];
    }
}
int query(int i,int j,int l=1,int r=n,int p=1)
{
    if(i>r || j<l)return 0;
    if(l>=i&&r<=j)return tree[p];
    int left=p*2,right=left+1,mid=(l+r)/2;
    int x=query(i,j,l,mid,left);
    int y=query(i,j,mid+1,r,right);
    return x+y;
}
void update(int idx,int v,int p=1,int l=1,int r=n)
{
    if(idx<l||idx>r)return;
    if(l==r)tree[p]+=v;
    else
    {
        int left=p*2,right=left+1,mid=(l+r)/2;
        update(idx,v,left,l,mid);
        update(idx,v,right,mid+1,r);
        tree[p]=tree[left]+tree[right];
    }
}
struct info
{
    int prop,sum;
}lazy[N*4];
void update(int i,int j,int v,int p=1,int l=1,int r=n)
{
    if(i>r || j<l)return;
    if(l>=i&&r<=j)
    {
        lazy[p].sum+=(r-l+1)*v;
        lazy[p].prop+=v;
        return;
    }
    int left=p*2,right=left+1,mid=(l+r)/2;
    update(i,j,v,left,l,mid);
    update(i,j,v,right,mid+1,right);
    lazy[p].sum=lazy[left].sum+lazy[right].sum+(r-l+1)*lazy[p].prop;
}
int query(int i,int j,int p=1,int l=1,int r=n,int carry=0)
{
    if(i>r || j<l)return 0;
    if(l>=i && r<=j)
        return lazy[p].sum+carry*(r-l+1);
    int left=p*2,right=left+1,mid=(l+r)/2;
    int x=query(i,j,left,l,mid,carry+lazy[p].prop);
    int y=query(i,j,right,mid+1,r,carry+lazy[p].prop);
    return x+y;
}
int main() {

    cin>>n;
    for(int i=1;i<n+1;i++)cin>>a[i];
    build();
  //  cout<<query(2,3);
    return 0;
    }
