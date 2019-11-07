#include <bits/stdc++.h>

using namespace std;
int r, c;

int rec(vector<vector<int>> &dp, vector<vector<int>> &grid, vector<vector<pair<int,int>>> &child, int x, int y)
{
    if(grid[x][y] == -1) return INT_MIN;
    if(x==r-1 && y==c-1)
        return grid[x][y];

    if(dp[x][y] != -1) return dp[x][y];

    int op1 = INT_MIN, op2 = INT_MIN;
    if(x<r-1) op1 = rec(dp, grid, child, x+1, y);
    if(y<c-1) op2 = rec(dp, grid, child, x, y+1);

    if(op1>op2)
    {
        child[x][y] = {x+1, y};
        dp[x][y] = grid[x][y] + op1;
    }

    else
    {
        child[x][y] = {x, y+1};
        dp[x][y] = grid[x][y] + op2;
    }

    return dp[x][y];
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m,0));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>grid[i][j];
    }

    r=n;
    c=m;

    vector<vector<int>> dp(n, vector<int>(m,-1));
    vector<vector<pair<int,int>>> child(n, vector<pair<int,int>>(m,{-1, -1}));
    
    

    cout<<"ANSWER = "<<rec(dp, grid, child, 0, 0)<<endl;
    grid[0][0] = 0;
    int x = child[0][0].first, y = child[0][0].second;
    while(!(x == r-1 && y==c-1))
    {
        grid[x][y] = 0;
        pair<int, int> p = child[x][y];
        x = p.first;
        y = p.second;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] < 0) cout<<grid[i][j]<<" ";
            else cout<<" "<<grid[i][j]<<" ";
        }
            
        cout<<endl;
    }
    cout<<endl;

    return 0;

}


// 7
// 9
// 1  0  0  0  0  0  0  0  0
// 0  0  0  0  0 -1  1 -1  0
// 0  0  1  1  0  0  0 -1  1
// 0  0 -1 -1 -1 -1 -1 -1  0
// 0  1  1 -1  1  0  1 -1  0
// 0  0  0  1  1  1  0  0  0
// 1  1  0  0  0  0  0  0  0

