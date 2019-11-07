#include<bits/stdc++.h>
using namespace std;

vector<int> rec(int id, vector<vector<int>> & graph, vector<vector<int>> &dp)
{
    if(dp[id][0] != -1) return {dp[id][0], dp[id][1]};

    if(graph[id].size() == 0) return {1, 0};
    vector<int> a1, a2;
    for(int i : graph[id])
    {
        vector<int> res = rec(i, graph, dp);
        a1.push_back(res[0]);
        a2.push_back(res[1]);
    }

    int res1 = 1;
    for(int i =0; i<a1.size(); i++)
        res1 += min(a1[i], a2[i]);

    int res2 = 0, f=0;
    for(int i =0; i<a1.size(); i++)
    {
        if(a1[i]<a2[i])
        {
            f=1;
            res2 += a1[i];
        }
        else res2 += a2[i];
    }

    if(!f)
    {
        int minn = a1[0];
        int id = 0;
        for(int i =1; i<a1.size(); i++)
        {
            if(a1[i]<minn)
            {
                minn = a1[i];
                id = i;
            }
        }
        res2 = res2-a2[id]+a1[id];
    }

    dp[id][0] = res1;
    dp[id][1] = res2;
    return {res1, res2};
}


int main()
{
    int n;
    cin>>n;
    vector<int> empty;
    vector<vector<int>> graph(n, empty);

    int edges;
    cin>>edges;

    int a,b;
    for(int i=0; i<edges; i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
    }

    vector<vector<int>> dp(n, vector<int>(2,-1));
    vector<int> res = rec(0, graph, dp);
    int ans = min(res[0], res[1]);
    if(n==1) ans = 1;
    cout<<"ANSWER = "<<ans<<endl;
}