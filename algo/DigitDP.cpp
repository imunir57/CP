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
typedef pair<ll,ll> pii;
typedef pair<int,string> psi;
typedef map<int,bool>mii;
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

int dp[10][2][82];
int x,n;
string s;
int digit(int i,bool fl,int sum)
{
    if(n==i)
    {
        if(sum==x)return 1;
        else return 0;
    }
    int &ret=dp[i][fl][sum];
    if(ret!=-1)
        return ret;

    int h=9;
    int ans=0;
    if(fl)///ith digit is decreased
    {
        for(int j=0;j<=h;j++) ///
            ans+=digit(i+1,fl,sum+j);
    }
    else ///ith digit is unchanged
    {
        h=s[i]-'0';
        for(int j=0;j<h;j++)
            ans+=digit(i+1,1,sum+j);
        ans+=digit(i+1,0,sum+h);
    }
    ret=ans;
    return ret;

}
int main()
{
    cin>>s;
    cin>>x;
    mem(dp,-1);
    n=s.length();
    int ans=digit(0,0,0);///idx,flag(0- no change, 1- decrease the number),sum
    cout<<ans;
}


