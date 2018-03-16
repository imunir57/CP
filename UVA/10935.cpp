#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cctype>
#include<string>
#include<vector>
#include<algorithm>
#define loop(a,b,c) for(int a=b;a<c;a++)
#define EPS 1e-5
#define redian acos(-1)/180
#define TC(t) scanf("%d",&t);while(t--)
#define SIZE 100000
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

int main()
{
    int a,b,x;
   while(scanf("%d %d",&a,&b)==2)
   {
       vector<int>A,B;
       if(a==0&&b==0)break;
       loop(i,0,a){
           scanf("%d",&x);
        A.push_back(x);
       }
       loop(i,0,b){
           scanf("%d",&x);
       B.push_back(x);
   }
       int ans=0;
       vector<int>::iterator p=A.begin();

       while(p!=A.end())
       {
           if(binary_search(B.begin(),B.end(),*p))ans++;
           p++;
       }
       printf("%d\n",ans);
   }

    return 0;
}


