#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>> path;
int init;

ll rec(ll mask, ll j, vector<vector<ll>> &graph, vector<vector<ll>> &dp, vector<vector<ll>> &dp2)
{
    if(!mask) return 0;
    ll n = graph.size();
    if(!(mask&(1<<j))) return INT_MAX;
    if(dp[mask][j] != -1) return dp[mask][j];
    
    ll val = INT_MAX;
    for(ll i=0; i<n; i++)
    {
        if(mask&(1<<i) && graph[i][j] != -1)
        {
            int temp = rec(mask^(1<<j),  i, graph, dp, dp2);
            if(val>temp+graph[i][j])
            {
                val = temp+graph[i][j];
                dp2[mask][j] = i;
            }
        }
    }

    return dp[mask][j]=val;
}


ll solve(vector<vector<ll>> &graph)
{
    ll n = graph.size();
    vector<vector<ll>> dp((1<<n), vector<ll>(n,-1));
    vector<vector<ll>> dp2((1<<n), vector<ll>(n,-1));
    for(ll i=0; i<n; i++)
    {
        dp[1<<i][i]=0;
    }
    ll mask = (1<<n)-1;
    ll minn = INT_MAX;
    for(ll i=0; i<n; i++)
    {
        dp[mask][i] = rec(mask, i, graph, dp, dp2);
        minn = min(minn, dp[mask][i]);
        if(minn = dp[mask][i]) init = i;
    }
    path = dp2;
    return minn;
}

int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>> graph(n, vector<ll>(n,0));
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
            cin>>graph[i][j];
    }

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
            cout<<graph[i][j]<<" ";

        cout<<endl;
    }

    ll ans = solve(graph);
    cout<<"ANSWER = "<<ans<<endl;

    int t = init;
    cout<<"PATH = ";
    int mask = (1<<n)-1, prev_mask;
    while(mask>0)
    {
        prev_mask = mask;
        cout<<t<<" ";
        mask = mask^(1<<t);
        t = path[prev_mask][t];
    }
    cout<<endl;
    return 0;
    
}

// 3
// 0  4 1
// 2  0 1
// -1 2 0