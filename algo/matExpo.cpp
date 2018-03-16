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
/*
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
int x8[]= {0,0,+1,-1,-1,+1,-1,+1};
int y8[]= {-1,+1,0,0,+1,+1,-1,-1};
int kx[]= {2,2,-2,-2,1,-1,1,-1};
int ky[]= {1,-1,1,-1,2,2,-2,-2};  */
int maxN;///size of matrix
struct matrix
{
    int size;
    vector<vi > mat;
    matrix(int k):size(k),mat(k,vi(k,0)){}
};
matrix matmul(matrix a,matrix b)
{
    matrix ans(a.size);
    int k;
    for(int i=0;i<maxN;i++)
        for(int j=0;j<maxN;j++)
            for(ans.mat[i][j]=k=0;k<maxN;k++)
                ans.mat[i][j]=ans.mat[i][j]+(a.mat[i][k]*b.mat[k][j]);
    return ans;

}
matrix matpow(matrix b,int p)
{
    matrix ans(b.size);
    for(int i=0;i<maxN;i++)
        for(int j=0;j<maxN;j++)
            ans.mat[i][j]=(i==j);
    while(p)
    {
        if(p&1)
            ans=matmul(ans,b);
        b=matmul(b,b);
        p/=2;
    }
    return ans;
}
int main()
{
    faster
    maxN=2;
    int n;///fibo^n
    while(cin>>n)
    {

        matrix x(2);
        x.mat[0][0]=x.mat[0][1]=x.mat[1][0]=1,x.mat[1][1]=0;///1 1
                                                            ///1 0
        x=matpow(x,n);
        cout<<x.mat[1][0]<<ln;
    }

}



