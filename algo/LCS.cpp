#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           1005
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

string a,b;
bool vis[N][N];
int dp[N][N];
int lcs(int i,int j)
{
    if(i>=a.size()||j>=b.size())return 0;
    if(vis[i][j])return dp[i][j];
    int ans=0;
    if(a[i]==b[j])ans=1+lcs(i+1,j+1);
    else
    {
        int x=lcs(i+1,j);
        int y=lcs(i,j+1);
        ans=max(x,y);
    }
    dp[i][j]=ans;
    vis[i][j]=1;
    return dp[i][j];
}
string path;
void printLcs(int i,int j)
{
    if(i>=a.size()||j>=b.size())
    {
        cout<<path;return;
    }
    if(a[i]==b[j])
    {
        path+=a[i];
        printLcs(i+1,j+1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1])printLcs(i+1,j);
        else printLcs(i,j+1);
    }
}
void printAll(int i,int j)
{
    if(i>=a.size()||j>=b.size())
    {
        cout<<path;
        return;
    }
    if(a[i]==b[j])
    {
        path+=a[i];
        printAll(i+1,j+1);
        path.pop_back();
    }
    else
    {
        if(dp[i][j+1]>dp[i+1][j])printAll(i,j+1);
        else if(dp[i+1][j]>dp[i][j+1])printAll(i+1,j);
        else
        {
            printAll(i+1,j);
            printAll(i,j+1);
        }
    }
}
int main()
{
    cin>>a>>b;
    cout<<lcs(0,0)<<ln;
    printAll(0,0);
    return 0;
}




