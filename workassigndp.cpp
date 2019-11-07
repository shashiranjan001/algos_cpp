#include<bits/stdc++.h>

using namespace std;

int count_set(int i)
{
    int s=0;
    while(i>0)
    {
        if(i&1) s++;
        i>>=1;
    }
    return s;
}
// int solve(vector<vector<int>> cost)
// {
//     int n =cost.size();
//     vector<int> dp(1<<n, INT_MAX);
//     dp[0]=0;
//     for(int i=0; i<(1<<n); i++)
//     {
//         int x = count_set(i);
//         for(int j=0; j<n; j++)
//         {
//             if(i&(1<<j) == 0)
//             {
//                 dp[i|1<<j] = min(dp[i|1<<j], dp[i]+cost[x][j]);
//             }
//         }
//     }

//     return dp[(1<<n)-1];
// }

int solve2(vector<int> &dp, vector<int> &dp2, vector<vector<int>> &cost, int mask)
{
    int n = cost.size();
    if(dp[mask] != -1) return dp[mask];
    // cout<<"HI"<<endl;
    int x = count_set(mask);
    // cout<<"X = "<<x<<endl;
    int s =INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(mask&(1<<i))
        {
            int t = cost[x-1][i]+solve2(dp, dp2, cost, mask^(1<<i));
            s = min(s, t);
            if(s==t) dp2[mask]=i;
        }
    }

    return dp[mask]=s;
}
int main()
{
    int n;
    cin>>n;
    cout<<"N = "<<n<<endl;
    vector<vector<int>> cost(n, vector<int>(n,0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin>>cost[i][j];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<cost[i][j]<<" ";
        cout<<endl;
    }

    vector<int> dp((1<<n), -1);
    vector<int> dp2((1<<n), -1);
    dp[0] = 0;
    int d = (1<<n)-1;
    cout<<"d = "<<d<<endl;
    cout<<"set bits in d = "<<count_set(d)<<endl;
    int ans = solve2(dp, dp2,cost, d);

    vector<int> s;
    s.push_back(dp2[d]);
    int t = d^(1<<dp2[d]);
    while(t)
    {
        s.push_back(dp2[t]);
        t^=(1<<dp2[t]);
    }

    for(int i=s.size()-1; i>=0; i--)
        cout<<s[i]<<" ";
    cout<<endl;
    cout<<"ANSWER = "<<ans<<endl;
    return 0;
}