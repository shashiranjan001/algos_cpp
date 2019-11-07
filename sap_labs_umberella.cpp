#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

ll rec(ll index, ll people, vector<vector<ll>> &dp, vector<ll> &u)
{
    if(people==0) return 0;
    if(index==0) return INT_MAX;

    if(u[index]>people) 
        return dp[index][people] = rec(index-1, people, dp ,u);

    ll a1 = rec(index-1, people, dp, u);
    ll a2 = 1+rec(index, people-u[index], dp, u);

    dp[index][people] = min(a1, a2);
    return dp[index][people];
}


int main()
{
    ll n;
    cin>>n;
    vector<ll> u(n+1,0);
    for(ll i=1; i<=n; i++)
        cin>>u[i];

    ll m;
    cin>>m;

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, -1));
    ll ans = rec(n, m, dp, u);
    if(ans == INT_MAX) ans = -1;
    cout<<"ANSWER = "<<ans<<endl;
}