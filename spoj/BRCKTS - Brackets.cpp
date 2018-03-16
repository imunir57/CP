#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           30010
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
typedef pair<ll,ll> pii;
typedef pair<int,string> psi;
typedef map<int,int>mii;
inline bool sc(int &_x){return scanf("%d",&_x)==1;}
inline bool sc(int &_x, int &_y){return sc(_x)&&sc(_y);}
inline bool sc(int &_x, int &_y, int &_z){return sc(_x)&&sc(_y)&&sc(_z);}
inline bool sc(int &_x, int &_y, int &_z, int &_zz){return sc(_x)&&sc(_y)&&sc(_z)&&sc(_zz);}
/*
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};
int kx[]= {2,2,-2,-2,1,-1,1,-1};
int ky[]= {1,-1,1,-1,2,2,-2,-2};  */
char a[N];
int tree[N*4][2],n;
void build(int p=1,int l=1,int r=n)
{
    if(l==r){
        if(a[l]=='(')tree[p][0]=1,tree[p][1]=0;//0-opening, 1-closing
        else tree[p][1]=1,tree[p][0]=0;
    }
    else
    {
        int m=(l+r)/2,left=p*2,right=left+1;
        build(left,l,m);
        build(right,m+1,r);
        int x=min(tree[left][0],tree[right][1]);

        tree[p][0]=tree[left][0]+tree[right][0]-x;
        tree[p][1]=tree[left][1]+tree[right][1]-x;

    }
}
bool query(int i,int j,int l=1,int r=n,int p=1)
{
    if(i>r || j<l)return 0;
    if(l>=i&&r<=j)return !(tree[p][0]||tree[p][1]);
    int left=p*2,right=left+1,mid=(l+r)/2;
    bool x=query(i,j,l,mid,left);
    bool y=query(i,j,mid+1,r,right);
    return (x&y);
}
void update(int idx,int p=1,int l=1,int r=n)
{
    if(idx<l||idx>r)return;
    if(l==r)
    {
        if(a[l]==')') a[l]='(', tree[p][0]=1,tree[p][1]=0;
        else a[l]=')', tree[p][1]=1,tree[p][0]=0;
    }
    else
    {
        int left=p*2,right=left+1,mid=(l+r)/2;
        update(idx,left,l,mid);
        update(idx,right,mid+1,r);

        int x=min(tree[left][0],tree[right][1]);

        tree[p][0]=tree[left][0]+tree[right][0]-x;
        tree[p][1]=tree[left][1]+tree[right][1]-x;
    }
}
int main()
{
    faster
    int cs=0;
    while(cin>>n)
    {
        lp(i,1,n+1)cin>>a[i];
        build();
        int q,x;cin>>q;
        cout<<"Test "<<++cs<<":\n";
        while(q--)
        {
            cin>>x;
            if(x)
                update(x);
            else
                cout<<(query(1,n)?"YES":"NO")<<ln;
        }
    }

}


