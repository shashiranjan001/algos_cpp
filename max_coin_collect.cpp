#include<bits/stdc++.h>

using namespace std;

int rec(int i, int j, int turn, vector<vector<vector<int>>> &dp, vector<int> &arr)
{
    if(dp[i][j][turn] != -1) return dp[i][j][turn];
    if(turn==0)
    {
        int maxxi = INT_MIN;
        maxxi = max(maxxi, arr[i]+rec(i+1, j, 1, dp, arr));
        maxxi = max(maxxi, arr[j]+rec(i, j-1, 1, dp, arr));
        return dp[i][j][turn]=maxxi;
    }

    else
    {
        int minn = INT_MAX;
        minn = min(minn, rec(i+1, j, 0, dp, arr));
        minn = min(minn, rec(i, j-1, 0, dp, arr));
        return dp[i][j][turn]=minn;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2,-1)));
    for(int i=0; i<n; i++)
    {
        dp[i][i][0] = arr[i];
        dp[i][i][1] = 0;
    }
    int ans = rec(0,arr.size()-1, 0, dp, arr);
    cout<<"ANSWER = "<<ans<<endl;
    return 0;
}