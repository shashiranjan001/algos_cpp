#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
bool isinvalid(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &visited)
{
    return(x<1||x>n||y<1||y>m||visited[x][y]==1||grid[x][y] == -1);
}
int rec(int x, int y, vector<vector<int>> &dp, vector<vector<int>> &grid, vector<vector<int>> &visited)
{
    if(x==n && y==m) return grid[x][y];
    if(dp[x][y] != -1)
        return dp[x][y];

 
    int maxxi = INT_MIN;
    for(int k=0; k<4; k++)
    {
        int nx = x+dir[k].first;
        int ny = y+dir[k].second;

        if(!isinvalid(nx,ny, grid, visited))
        {
            visited[nx][ny] = 1;
            maxxi = max(maxxi, rec(nx,ny,dp,grid,visited));
            visited[nx][ny] = 0;
        }
    }

    dp[x][y] = grid[x][y]+maxxi;
    return dp[x][y];
}


int main()
{
    cin>>n>>m;
    vector<vector<int>> grid(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
        cin>>grid[i][j];

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    vector<vector<int>> visited(n+1, vector<int>(m+1, 0));
    int ans = rec(1,1, dp, grid, visited);
    cout<<"ANSWER = "<<ans<<endl;
    // for(int i=1; i<=n; i++)
    // {
    //     for(int j=1; j<=m; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    return 0;
}