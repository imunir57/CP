#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           10005
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
int tree[26][N];
int endmark[N],sz;
bool created[N];

void insert(string s)
{
    int v=0;
    for(int i=0;i<s.size();i++)
    {
        int x=s[i]-'a';
        if(!created[tree[x][v]])
        {
            tree[x][v]=++sz;
            created[sz]=1;
        }
        v=tree[x][v];
    }
    ++endmark[v];
}
bool search(string s)
{
    int v=0;
    for(int i=0;i<s.size();i++)
    {
        int x=s[i]-'a';
        if(!created[tree[x][v]])
            return false;
        v=tree[x][v];
    }
    return endmark[v]>0;
}
int main()
{
    int n,q;cin>>n>>q;
    string x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert(x);
    }
    while(q--)
    {
        cin>>x;
        if(search(x))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
