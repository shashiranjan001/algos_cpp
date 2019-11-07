#include<bits/stdc++.h>
using namespace std;
int r, c;

int rec(vector<vector<vector<int>>> &dp, vector<vector<int>> &grid, int r1, int c1, int r2)
{
    int c2 = r1+c1 -r2;
    if(grid[r1][c1] == -1 || grid[r2][c2] == -1) return INT_MIN;
    if(r1==r-1 && r2 == r-1 && c1 == c-1)
    {
        return (grid[r-1][c-1]);
    }

    if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];
    int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN, op4 = INT_MIN;
    if(r1<r-1 && r2<r-1)
        op1 = rec(dp, grid, r1+1, c1, r2+1);

    if(r1<r-1 && c2<c-1)
        op2 = rec(dp, grid, r1+1, c1, r2);

    if(c1<c-1 && r2<r-1)
        op3 = rec(dp, grid, r1, c1+1, r2+1);

    if(c1<c-1 && c2<c-1)
        op4 = rec(dp, grid, r1, c1+1, r2);

    int grid_val=0;
    if(r1==r2 && c1==c2)
        grid_val = grid[r1][c1];
        
    else
        grid_val=grid[r1][c1]+grid[r2][c2];

    dp[r1][c1][r2] = grid_val + max(op1, max(op2, max(op3, op4)));
    return dp[r1][c1][r2];
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

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n, -1)));

    int ans = rec(dp, grid, 0,0,0);
    cout<<"Answer = "<<ans<<endl;
    return 0;
}

// 7
// 9
// 1  0  0  0  0  0  0  0  0
// 0  0  0  0  0  1  1 -1  0
// 0  0  1  1  0  0  0 -1  1
// 0  0 -1 -1 -1 -1  1 -1  0
// 0  1  0 -1  1  0  1 -1  0
// 0  0  0 -1  1  1  0  0  0
// 1  0  0  0  0  0  0  0  0