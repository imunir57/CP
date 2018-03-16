#include<bits/stdc++.h>
using namespace std;
#define Max 1e9
#define N 100
vector<pair<pair<int,int>,int > >edge;
int dist[N];
bool hasNegativeCylcle(int nodes,int source)
{
    for(int i=0;i<N;i++)
        dist[i]=Max;
    dist[source]=0;
    for(int i=1;i<nodes;i++)
    {
        for(int j=0;j<edge.size();j++)
        {
            int u=edge[j].first.first;
            int v=edge[j].first.second;
            int w=edge[j].second;
            if(dist[v]>dist[u]+w)
                dist[v]=dist[u]+w;
        }
    }
    for(int i=0;i<edge.size();i++)
        {
            int u=edge[i].first.first;
            int v=edge[i].first.second;
            int w=edge[i].second;
            if(dist[v]>dist[u]+w)
                return true;
        }
    return false;
}

int main()
{

    int node,edges;
    cin>>node>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back(make_pair(make_pair(u,v),w));
        edge.push_back(make_pair(make_pair(v,u),w));
    }
    cout<<hasNegativeCylcle(node,1);
}

/*
3 3
1 2 3
1 3 -10
2 3 2
*/
