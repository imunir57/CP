#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           25145
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

const int MOD=10;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<int,string> psi;
typedef map<int,int>mii;
inline bool sc(int &_x) {
    return scanf("%d",&_x)==1;
}
inline bool sc(int &_x, int &_y) {
    return sc(_x)&&sc(_y) ;
}
inline bool sc(int &_x, int &_y, int &_z) {
    return sc(_x)&&sc(_y)&&sc(_z) ;
}
inline bool sc(int &_x, int &_y, int &_z, int &_zz) {
    return sc(_x)&&sc(_y)&&sc(_z)&&sc(_zz) ;
}
/*      direction
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};
int kx[]={2,2,-2,-2,1,-1,1,-1};
int ky[]={1,-1,1,-1,2,2,-2,-2};*/
struct node
{
    bool endmark;
    node *next[2];
    int c;
    node()
    {
        c=0;
        endmark=0;
        loop(i,0,2)next[i]=NULL;
    }
}*root;

void insert(string str,int len)
{
    node *curr=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'0';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr->c++;
        curr=curr->next[id];
    }
    curr->endmark=1;
}
int search(string str,int len)
{
    int mx=0;
    node *curr=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'0';
        if(curr->next[id]==NULL)return mx;
        mx=max(mx,curr->c);
        cout<<curr->c<<'\n';
        curr=curr->next[id];
    }
}
void del(node *curr)
{
    for(int i=0;i<2;i++)
        if(curr->next[i])
            del(curr->next[i]);
        delete(curr);
}
int main()
{

    root=new node();
    int n;cin>>n;
    vs s;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        s.pb(str);
        insert(str,str.length());
    }
  //  cout<<"bug";
    int mx=0;
    for(auto i:s)
    {
        mx=max(mx,search(i,i.size()));
    }
    cout<<mx;

    del(root);

    return 0;
}
