#include<bits/stdc++.h>

using namespace std;
int dp[5][9][2];
vector<int> digits;
int a, b,d,x;
int rec(int pos, int freq, int flag)
{
    if(freq>x) return 0;
    if(pos == digits.size())
    {
        return (freq == x);
    }
    if(dp[pos][freq][flag] != -1)
        return dp[pos][freq][flag];

    int rtr=0;
    int k=9;
    if(flag) k=digits[pos];
    cout<<"K = "<<k<<endl;
    for(int i=0; i<=k; i++)
    {
        int nf=0;
        if(flag && i==digits[pos]) nf=1;
        int add=0;
        if(i==x) add=1;
        rtr += rec(pos+1, freq+add, nf);
    }

    return dp[pos][freq][flag]=rtr;
}

int solve(int n)
{
    digits.clear();
    while(n)
    {
        digits.push_back(n%10);
        n/=10;
    }
    reverse(digits.begin(), digits.end());
    memset(dp, -1, sizeof(dp));

    cout<<"digits size = "<<digits.size()<<endl;
    return rec(0, 0, 1);
}
int main()
{
    
    cin>>a>>b>>d>>x;
    int ans = solve(a);
    cout<<"ANS = "<<ans<<endl;
}