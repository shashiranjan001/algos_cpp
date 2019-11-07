#include<bits/stdc++.h>

using namespace std;

#define MAXX 10000

int n, m, sr, sc, tr, tc;
int grid[MAXX][MAXX];
int dp[MAXX][MAXX];
bool visited[MAXX][MAXX];

bool isinvalid(int r, int c)
{
    return (r<1 || r>n || c<1 || c>m || grid[r][c] == 0);
}

int rec(int r, int c)
{
    if(dp[r][c] != -1) return dp[r][c];

    int minn = INT_MAX;
    for(int i=r-1; i>=1; i--)
    {
        if(!visited[i][c] && !isinvalid(i,c))
        {
            visited[r][c] = true;
            minn = min(minn, max(r-i ,rec(i,c)));
            visited[r][c] = false;
        }
    }

    for(int i=r+1; i<=n; i++)
    {
        if(!visited[i][c] && !isinvalid(i,c))
        {
            visited[r][c] = true;
            minn = min(minn, max(i-r ,rec(i,c)));
            visited[r][c] = false;
        }
    }

    if(!visited[r][c-1] && !isinvalid(r,c-1))
    {
        visited[r][c-1] = true;
        minn = min(minn, rec(r, c-1));
        visited[r][c-1] = false;
    }

    if(!visited[r][c+1] && !isinvalid(r,c+1))
    {
        visited[r][c+1] = true;
        minn = min(minn, rec(r, c+1));
        visited[r][c+1] = false;
    }

    dp[r][c] = minn;
    return dp[r][c];
}

int main()
{

    cin>>n>>m;
    cout<<"n = "<<n<<" m = "<<m<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cin>>grid[i][j];
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cout<<grid[i][j]<<"\t";
        cout<<endl;
    }

    sr = n, sc=1;
    cout<<"sr = "<<sr<<" sc = "<<sc<<endl;
    cin>>tr>>tc;
    cout<<"tr = "<<tr<<" tc = "<<tc<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            dp[i][j] = -1;
    }
    dp[tr][tc] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            visited[i][j] = false;
    }
    // for(int i=1; i<=n; i++)
    // {
    //     for(int j=1; j<=m; j++)
    //         cout<<dp[i][j]<<"\t";
    //     cout<<endl;
    // }
    
    int ans = rec(sr, sc);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cout<<dp[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"ANS = "<<ans<<endl;
    return 0;
}

// 5 8
// 1 1 1 1 0 0 0 0
// 0 0 0 1 0 1 1 1
// 1 1 1 0 0 1 0 0
// 0 0 0 0 0 0 1 0
// 1 1 1 1 1 1 1 1
// 2 4