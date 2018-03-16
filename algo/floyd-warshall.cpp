#include<bits/stdc++.h>
using namespace std;
#define N 100
int adj[N][N];

void floyd(int n)
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                    adj[i][j]=max(adj[i][j],adj[i][k]+adj[k][j]);
            }
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            if(i==j)
                adj[i][j]=0;
            else
                adj[i][j]=1e9;
        }
    for(int i=0;i<edge;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        adj[u][v]=w;
        adj[v][u]=w;
    }
    floyd(node);
}
