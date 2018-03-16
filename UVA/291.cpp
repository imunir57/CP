#include<bits/stdc++.h>
using namespace std;
int mat[5][5] = {
    {0,1,1,0,1},
    {1,0,1,0,1},
    {1,1,0,1,1},
    {0,0,1,0,1},
    {1,1,1,1,0}
    };
int ans[8] = {0};

void dfs(int idx, int now)
{
    ans[idx] = now;

    if(idx==8)
    {
        for(int i=0;i<9;i++)
            printf("%d",ans[i]+1);
        printf("\n");
        return;
    }
    for(int i=0;i<5;i++)
    {
        if(mat[now][i]==1)
        {
            mat[now][i]=mat[i][now]=0;
            dfs(idx+1,i);
            mat[now][i]=mat[i][now]=1;
        }
    }
}
int main()
{
    dfs(0, 0);
    return 0;

}
