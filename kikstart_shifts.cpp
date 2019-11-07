#include<bits/stdc++.h>

using namespace std;

int ways(vector<vector<int>> dp, int req, vector<int> a, int id)
{
    if(req<=0) return pow(2, id+1);
    if(req>0 && id<0) return 0;
    

    if(dp[req][id] != -1) return dp[req][id];

    int ans = 0;
    ans += ways(dp, req, a, id-1) + ways(dp, req-a[id], a, id-1);
    dp[req][id] = ans;
    return dp[req][id]; 
}

int main()
{
    int t;
    cin>>t;
    for(int l=1; l<=t; l++)
    {
        int n, h;
        cin>>n>>h;
        int saninda =0, sboman=0;
        vector<int> aninda(n,0), boman(n,0);
        for(int i=0; i<n; i++)
        {
            cin>>aninda[i];
            saninda+=aninda[i];
        }

        for(int i=0; i<n; i++)
        {
            cin>>boman[i];
            sboman+=boman[i];
        }

        int out;
        if(saninda < h || sboman<h) out = 0;

        else
        {
            vector<vector<int>> dpa(h+1, vector<int>(n, -1));
            int wa = ways(dpa, h, aninda, n-1);

            vector<vector<int>> dpb(h+1, vector<int>(n, -1));
            int wb = ways(dpb, h, boman, n-1);

            out = wa*wb;
        }

        cout<<"Case #"<<l<<": "<<out<<endl;
    } 
}