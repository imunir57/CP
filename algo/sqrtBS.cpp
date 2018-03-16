#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#define loop(a,b,c) for(int a=b;a<c;a++)
#define EPS 1e-9
#define TC(t) scanf("%d",&t);while(t--)
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

int lowerbound(int a[],int n,int b)
{
    int lo=0,hi=n,mid,lower=-1;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(a[mid]>=b)   ///upper <=
        {
            if(b==a[mid])
                lower=mid;
            hi=mid-1;       ///lo
        }
        else
            lo=mid+1;       ///hi
    }
    return lower;
}

int main()
{
    int arr[9]={1,2,3,3,4,4,5,6,8};
    cout<<lowerbound(arr,8,4)<<endl;
    ///sqrt
    double n=90;
    double lo=0,hi=n,mid;
    int i=0;
    while(i<64)
    {
        mid=(lo+hi)/2;
        double sq=mid*mid;
        if(fabs(sq-n)<=EPS)
            break;
        else if(sq>n)
            hi=mid;
        else
            lo=mid;
i++;
    }
    cout<<mid;

    return 0;
}

