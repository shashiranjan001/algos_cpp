#include <bits/stdc++.h>
using namespace std;

int r, c, sr, sc, tr, tc;
vector<pair<int ,int>> dir;
int code(int i, int j)
{
    return 1<<(c*i+j);
}
bool isinvalid(vector<vector<int>> &grid, int x, int y)
{
    return(x>=r || x<0 || y>=c || y<0|| grid[x][y]==-1);
}


int rec(vector<vector<vector<int>>> dp, vector<vector<int>> &grid, int x, int y, int total)
{
    if(isinvalid(grid, x,y)) return 0;
    if(x==tr && y==tc)
    {
        if(total == 0) return 1;
        return 0;
    }

    if(dp[x][y][total] != -1) return dp[x][y][total];
    int sum=0;
    for(int i=0; i<4; i++)
    {
        int xx = x+dir[i].first;
        int yy = y+dir[i].second;
        if(total & code(xx,yy))
            sum += rec(dp, grid, xx,yy, total^code(xx,yy));
    }

    dp[x][y][total] = sum;
    return sum;
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

    dir.push_back({1,0});
    dir.push_back({-1,0});
    dir.push_back({0,1});
    dir.push_back({0,-1});

    int total=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j]%2==0)
                total |= code(i,j);

            if(grid[i][j] == 1)
            {
                sr=i;
                sc=j;
            }

            else if(grid[i][j] == 2)
            {
                tr=i;
                tc=j;
            }
        }
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(1<<n*m, -1)));
    cout<<"ANSWER = "<<rec(dp, grid, sr, sc, total)<<endl;
    return 0;

}




// class Solution {
//     int ans;
//     int[][] grid;
//     int R, C;
//     int tr, tc, target;
//     int[] dr = new int[]{0, -1, 0, 1};
//     int[] dc = new int[]{1, 0, -1, 0};
//     Integer[][][] memo;

//     public int uniquePathsIII(int[][] grid) {
//         this.grid = grid;
//         R = grid.length;
//         C = grid[0].length;
//         target = 0;

//         int sr = 0, sc = 0;
//         for (int r = 0; r < R; ++r)
//             for (int c = 0; c < C; ++c) {
//                 if (grid[r][c] % 2 == 0)
//                     target |= code(r, c);

//                 if (grid[r][c] == 1) {
//                     sr = r;
//                     sc = c;
//                 } else if (grid[r][c] == 2) {
//                     tr = r;
//                     tc = c;
//                 }
//             }

//         memo = new Integer[R][C][1 << R*C];
//         return dp(sr, sc, target);
//     }

//     public int code(int r, int c) {
//         return 1 << (r * C + c);
//     }

//     public Integer dp(int r, int c, int todo) {
//         if (memo[r][c][todo] != null)
//             return memo[r][c][todo];

//         if (r == tr && c == tc) {
//             return todo == 0 ? 1 : 0;
//         }

//         int ans = 0;
//         for (int k = 0; k < 4; ++k) {
//             int nr = r + dr[k];
//             int nc = c + dc[k];
//             if (0 <= nr && nr < R && 0 <= nc && nc < C) {
//                 if ((todo & code(nr, nc)) != 0)
//                     ans += dp(nr, nc, todo ^ code(nr, nc));
//             }
//         }
//         memo[r][c][todo] = ans;
//         return ans;
//     }
// }