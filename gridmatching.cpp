#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> visited;
int n;
vector<pair<int,int>> d{{1,0},{-1,0},{0,1},{0,-1}};
bool isvalid(int x, int y)
{
    if(x>=0 && x<n && y>=0 && y<n) return 1;
    return 0;
}

int dfs(int x, int y, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    
    int res=0;
    if(grid1[x][y] == grid2[x][y]) res=1;
    visited[x][y] =1;
    for(int i=0; i<4; i++)
    {
        int nx = x+d[i].first;
        int ny = y+d[i].second;

        if(!isvalid(nx, ny)) continue;
        
        if(visited[nx][ny]) continue;

        if(grid1[nx][ny] == 1|| grid2[nx][ny] == 1)
        {
            cout<<"nx : "<<nx<<" ny : "<<ny<<endl;
            res *=dfs(nx,ny,grid1, grid2);
        }

    }
    cout<<"res = "<<res<<endl;
    return res;
}

int solve(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    visited.resize(n);
    for(int i=0; i<n; i++)
    {
        visited[i].resize(n);
        for(int j=0; j<n; j++)
            visited[i][j] = 0;
    }
    

    int ways=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<"i : "<<i<<" j : "<<j<<endl;
            if(visited[i][j]) continue;
            visited[i][j] =1;
            if(grid1[i][j] == 1|| grid2[i][j] == 1)
                ways += dfs(i,j,grid1, grid2), cout<<"ways = "<<ways<<endl;
        }
    }
    // cout<<endl;
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<n; j++)
    //         cout<<visited[i][j]<<" ";
    //     cout<<endl;
    // }

    return ways;
}

int main()
{
    cin>>n;
    
    vector<vector<int>> grid1(n, vector<int>(n,0));
    vector<vector<int>> grid2(n, vector<int>(n,0));

    

    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        cin>>grid1[i][j];

    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        cin>>grid2[i][j];

    

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<grid1[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<grid2[i][j]<<" ";
        cout<<endl;
    }

    cout<<"n = "<<n<<endl;
    
    
    int count = solve(grid1, grid2);
    cout<<"ANSWER = "<<count<<endl;
    return 0;
}
