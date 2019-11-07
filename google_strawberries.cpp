#include<bits/stdc++.h>

using namespace std;

int rec(int id, int wt, vector<int> &arr, vector<vector<int>> &dp, vector<vector<int>> &dp2)
{
    if(id == 1)
    {
        if(arr[0]<=wt)
        {
            dp2[id] = {id};
            return arr[0];
        }
        else 
        {
            dp2[id] = {};
            return 0;
        }
    }
    if(dp[id][wt] != -1)    return dp[id][wt];

    if(arr[id-1] > wt)
    {
        dp2[id] = dp2[id-1];
        return dp[id][wt] = rec(id-1, wt, arr, dp, dp2);
    }
    int a1 = rec(id-1, wt, arr, dp, dp2);
    int a2 = arr[id-1] + rec(id-2, wt-arr[id-1], arr, dp, dp2);

    if(a1>a2)
    {
        dp2[id] = dp2[id-1];
        dp[id][wt] = a1;
    }
    else
    {
        dp2[id] = dp2[id-2];
        dp2[id].push_back(id);
        dp[id][wt] = a2;
    }
    

    return dp[id][wt];
} 


int main()
{
    int m, n;
    cin>>m>>n;
    cout<<"N = "<<n<<" M = "<<m<<endl;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    vector<vector<int>> dp2(n+1);
    vector<int> empty;
    dp2[0] = empty;
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int i=0; i<=m; i++)
        dp[0][i] = 0;

    int ans = rec(n, m, arr, dp, dp2);
    cout<<"ANSWER = "<<ans<<endl;
    for(int x : dp2[n])
        cout<<x<<" ";
    cout<<endl;
    return 0;
}