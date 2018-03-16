#include<bits/stdc++.h>
using namespace std;

#define N 105
#define INF 1e9
int g[N][N];
void floyd(int n)
{
    for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                        g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
}
int main() {
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)
            {
                if(i==j)
                    g[i][j]=0;
                else
                {
                    string in;
                    cin>>in;
                    if(in=="x")
                        g[i][j]=INF;
                    else
                        g[i][j]=atoi(in.c_str());
                    g[j][i] = g[i][j];
                }
            }
        floyd(n);
        int ans=0;
        for(int i=1;i<n;i++)
            ans=max(ans,g[0][i]);

        cout<<ans<<'\n';
    }
    return 0;
}
