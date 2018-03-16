//Abinash Ghosh
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <limits>
using  namespace  std;

#define PI acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORR(i, b, e) for(int i = b; i >= e; i--)
#define FORI(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define ppr(a) cout<<a.x<<" "<<a.y<<"\n"
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define MAX 100007
#define EPS 1e-9

int main()
{
    int myints[] = {10,10,10,20,20,20,30,30,40,50,50},lb,ub;
    //               0  1  2  3  4  5  6  7  8  9 10
    //               0  1 .....................n-1 n
    vector<int> v(myints,myints+11);
    ///lowerbound
    {
        /// if value exists then it returns  the first occurence position
        lb=lower_bound(v.begin(),v.end(),10)-v.begin();
        pr2(lb,v[lb]);///0 10

        /// if value does not exist and v[0]<value<v[n] then it return (minimum value) > value  position
        lb=lower_bound(v.begin(),v.end(),21)-v.begin();
        pr2(lb,v[lb]);///6 30

        /// if value does not exist and value<v[0] then it return 0th  position
        lb=lower_bound(v.begin(),v.end(),6)-v.begin();
        pr2(lb,v[lb]);///0 10

        /// if value does not exist and value>v[n] then it return (n+1)th position
        lb=lower_bound(v.begin(),v.end(),51)-v.begin();
        pr2(lb,v[lb]);///11 0
    }
    /// upperbound
    /// Comment : return minimum value's position which > val
    {
        /// if value exists then it returns  the last occurence position+1
        ub=upper_bound(v.begin(),v.end(),40)-v.begin();
        pr2(ub,v[ub]);///9 50

        /// if value does not exist and v[0]<value<v[n] then it return (minimum value) > value  position
        ub=upper_bound(v.begin(),v.end(),41)-v.begin();
        pr2(ub,v[ub]);///9 50

        /// if value does not exist and value<v[0] then it return 0th  position
        ub=upper_bound(v.begin(),v.end(),6)-v.begin();
        pr2(ub,v[ub]);///0 10

        /// if value does not exist and value>v[n] then it return (n+1)th position
        ub=upper_bound(v.begin(),v.end(),51)-v.begin();
        pr2(ub,v[ub]);///11 0
    }
    return 0;
}





