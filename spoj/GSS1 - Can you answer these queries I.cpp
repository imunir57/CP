#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           50005
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
int a[N],n;
struct segment
{
    int sum,l,r,ans;
}tree[N*4];
segment combine(segment left,segment right)
{
    segment ret;
    ret.sum=left.sum+right.sum;
    ret.l=max(left.l,left.sum+right.l);
    ret.r=max(right.r,right.sum+left.r);
    ret.ans=max(max(left.ans,right.ans),left.r+right.l);
    return ret;
}
void build(int p=1,int l=1,int r=n)
{
    if(l==r){
        tree[p].ans=tree[p].l=tree[p].r=tree[p].sum=a[l];
    }
    else
    {
        int m=(l+r)/2,left=p*2,right=left+1;
        build(left,l,m);
        build(right,m+1,r);
        tree[p]=combine(tree[left],tree[right]);
    }
}
segment query(int i,int j,int l=1,int r=n,int p=1)
{
    if(l==i&&r==j)return tree[p];
    int left=p*2,right=left+1,mid=(l+r)/2;
    if(j<=mid)
        return query(i,j,l,mid,left);
    if(i>mid)
        return query(i,j,mid+1,r,right);
    segment tl=query(i,mid,l,mid,left);
    segment tr=query(mid+1,j,mid+1,r,right);
    return combine(tl,tr);
}
//void update(int idx,int v,int p=1,int l=1,int r=n)
//{
//    if(idx<l||idx>r)return;
//    if(l==r)tree[p]+=v;
//    else
//    {
//        int left=p*2,right=left+1,mid=(l+r)/2;
//        update(idx,v,left,l,mid);
//        update(idx,v,right,mid+1,r);
//        tree[p]=tree[left]+tree[right];
//    }
//}
int main()
{
    faster
    cin>>n;
    lp(i,1,n+1)cin>>a[i];
    build();
    int q;cin>>q;
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<query(l,r).ans<<ln;
    }
    return 0;
}
