#include<bits/stdc++.h>

using namespace std;
unordered_map<int,int> mp;
int rev(int n);
int logic2(int n)
{
    int cost=0;
    int x = n;
    int lsb = n%10;
    x = x-lsb+1;
    //cout<<"\nx = "<<x<<endl;
    cost += n-x+1;
    x = rev(x);
    //cout<<"x = "<<x<<endl;
    int d=0, j=x;
    while(j) d++,j/=10;
    //cout<<"d = "<<d<<endl;
    int s =0;
    for(int i=0; i<d-1; i++)
    {
        s += 9;
        if(i!=d-2)s *= 10;
    }

    s -= 8;
    //cout<<"s = "<<s<<endl;
    cost += x-s;
    cost += mp[s];
    return cost;
}

int rev(int n)
{
    vector<int> d;
    int j=n;
    while(j)
    {
        d.push_back(j%10);
        j/=10;
    }
    int res = 0;
    for(int i=0; i<d.size(); i++)
    {
        res += d[i];
        if(i<d.size()-1) res *= 10;
    }

    return res;
}
int main()
{
    int n=1e6;
    int dp[n];
    for(int i=0; i<n; i++) dp[i]=n;
    for(int i=0; i<=10; i++)
        dp[i]=i;

    for(int i=11; i<n; i++)
    {
        dp[i] = min(dp[i-1]+1, dp[i]);
        int x = rev(i);
        if(x<n)
        {
            dp[x] = min(dp[x], dp[i]+1);
        }
    }
    mp[1] = 1;
    mp[91] = 20;
    mp[991] = 129;
    mp[9991] = 1138;
    int m = 4875;
    cout<<m<<" = "<<dp[m]<<endl;
    cout<<m<<" = "<<logic2(m)<<endl;
}