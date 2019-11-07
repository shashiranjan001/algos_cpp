#include<bits/stdc++.h>
using namespace std;

int max_sum(vector<int> &a, vector<int> &dp, int pos)
{
    if(pos==0) return a[0];
    if(pos==1) return dp[1] = max(a[0], a[1]);
    if(dp[pos] != -1) return dp[pos];

    dp[pos] = max(max_sum(a, dp, pos-1), max(max_sum(a, dp, pos-2)+a[pos], max(a[pos], max_sum(a, dp, pos-2))));
    return dp[pos];
}


int max_sum2(vector<int> &a, vector<int> &dp, int pos)
{
    if(pos==0) return 0;
    if(pos==1) return a[1];
    if(dp[pos] != -1) return dp[pos];

    dp[pos] = max(max_sum2(a, dp, pos-1), max(max_sum2(a, dp, pos-2)+a[pos], max(a[pos], max_sum2(a, dp, pos-2))));
    return dp[pos];
}


int main()
{
    vector<int> a{1, 2, 3, 1};
    vector<int> dp(a.size(), -1);
    cout<<max_sum(a, dp, a.size()-2)<<endl;
    vector<int> dp2(a.size(), -1);
    cout<<max_sum2(a, dp2, a.size()-1)<<endl;
    return 0;
}