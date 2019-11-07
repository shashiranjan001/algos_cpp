#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll tr, tc;
ll mx_count;
vector<vector<ll>> dir{{1,0}, {-1,0}, {0,-1}, {0,1}};
map<ll, ll> mp;
vector<vector<ll>> grid;
bool isvalid(ll x, ll y)
{
    return (x>=0 && x<n && y>=0 && y<n && grid[x][y] != 1);
}

ll rec(ll x, ll y, ll mask, vector<vector<ll>> &grid, vector<vector<ll>> &visited, vector<vector<vector<ll>>> &dp)
{
    if(dp[x][y][mask] != -1) return dp[x][y][mask];
    
    if(x == tr && y==tc)
    {
        if(mask == ((1<<mx_count)-1)) return 0;
        return INT_MAX;
    }


    ll minn = INT_MAX;
    for(ll i=0; i<4; i++)
    {
        ll nx = x+dir[i][0];
        ll ny = y+dir[i][1];
        if(!isvalid(nx, ny)) continue;
        if(visited[nx][ny]) continue;


        if(grid[nx][ny] == 2) mask |= (1<<mp[nx*n+ny]);
        visited[x][y] = 1;
        minn = min(minn, 1+rec(nx, ny, mask, grid, visited, dp));
        mask ^= (1<<mp[nx*n+ny]);
        visited[nx][ny] = 0;
    }
    return dp[x][y][mask] = minn;
}

int main()
{
    cin>>n;
    vector<vector<ll>> grid2(n, vector<ll>(n,0));
    grid = grid2;
    //ll bitmask = 0;
    mx_count =0;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            cin>>grid[i][j];
            if(grid[i][j] == 2)
            {
                mp[i*n+j] = mx_count++;
            }
        }
    }
    cin>>tr>>tc;
    vector<vector<ll>> visited(n, vector<ll>(n,0));

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n,vector<ll>(1<<mx_count, -1)));

    ll ans = rec(0,0,0,grid,visited,dp);
    if(ans >= INT_MAX) ans = -1;

    cout<<"ANSWER = "<<ans<<endl;
}

// 3
// 0 2 1
// 1 2 0
// 1 0 0
// 2 2