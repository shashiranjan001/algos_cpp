#include<bits/stdc++.h>

using namespace std;

int rec(int mask, int j, vector<vector<int>> &graph, vector<vector<int>> &dp)
{
    int n = graph.size();
    if(!mask) return 1;
    if(!(mask&(1<<j))) return 0;
    if(dp[mask][j] != -1) return dp[mask][j];
    for(int i=0; i<n; i++)
    {
        if(mask&(1<<i) && graph[i][j]==1)
            dp[mask][j] = rec(mask^(1<<j),  i, graph, dp);
        if(dp[mask][j] == 1)
            return dp[mask][j];
    }

    return 0;
}


int solve(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> dp((1<<n), vector<int>(n,-1));
    for(int i=0; i<n; i++)
    {
        dp[1<<i][i]=1;
    }
    int mask = (1<<n)-1;
    for(int i=0; i<n; i++)
    {
        if(rec(mask, i, graph, dp) == 1) return 1;
    }

    return 0;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> graph(n, vector<int>(n,0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin>>graph[i][j];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<graph[i][j]<<" ";

        cout<<endl;
    }

    int ans = solve(graph);
    cout<<"ANSWER = "<<ans<<endl;
}