#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cctype>
#include<string>
#include<vector>
#include<algorithm>
#define loop(a,b,c) for(int a=b;a<c;a++)
#define EPS 1e-4
#define PI acos(-1)/180
#define TC(t) scanf("%d",&t);while(t--)
#define SIZE 50001
#define space ' '
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
/// Function to merge the two halves arr[l..m] and arr[m+1..r] of array arr[]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];   /// create temp arrays

    for(i = 0; i < n1; i++) /// Copy data to temp arrays L[] and R[]
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /// Merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];  /// Copy the remaining elements of L[], if there are any

    while (j < n2)
        arr[k++] = R[j++];  /// Copy the remaining elements of R[], if there are any
}

/** l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2; ///Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
        int a[]={3,5,2,1,4,6};//3 5 2 1 4 6
        mergeSort(a,0,5);
        loop(i,0,6)cout<<a[i]<<space;
}
