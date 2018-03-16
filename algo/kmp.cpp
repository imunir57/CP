#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<iostream>
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
#define loop(a,b,c) for(int a=b;a<(c);a++)
#define EPS         1e-9
#define PI          acos(-1)
#define redian      180/PI
#define TC(t)       scanf("%d",&t);while(t--)
#define SIZE        100005
#define space       ' '
#define line        '\n'
#define pb          push_back
#define pp          pop_back
#define mk          make_pair
#define X           first
#define Y           second

const int MOD=1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef stack<int> si;
typedef stack<string> ss;
typedef queue<int> qi;
typedef queue<string> qs;
typedef pair<int,int> pii;
typedef pair<string,int>psi;

/*      direction
int x4[]={1,-1,0,0};
int y4[]={0,0,1,-1};
int x8[]={0,0,+1,-1,-1,+1,-1,+1};
int y8[]={-1,+1,0,0,+1,+1,-1,-1};
                                    */

int b[SIZE];

void KMPprocess(char p[],int m)
{
    int i=0,j=-1;
    b[0]=-1;
    while(i<m)
    {
        while(j>=0&&p[i]!=p[j])j=b[j];
        i++;j++;
        b[i]=j;
    }
}

void KMPsearch(char t[],char p[],int n,int m)
{
    KMPprocess(p,m);
    int i=0,j=0;
    while(i<n)
    {
        while(j>=0&&t[i]!=p[j]) j=b[j];
        i++;j++;
        if(j==m)
        {
            cout<<"found at index "<<i-j<<line;
            j=b[j];
        }
    }
}
int main()
{
    char a[]="ACABAABABDABABA";
    char c[]="ABBAA";
    KMPsearch(a,c,strlen(a),strlen(c));
    loop(i,1,6)cout<<b[i]<<space;

    return 0;
}
