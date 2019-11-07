#include<bits/stdc++.h>

using namespace std;
int dp[5][45][2];
vector<int> digits;
int sum(int n)
{
    int s=0;
    for(int i=0; i<=n; i++)
    {
        int x=i;
        vector<int> a(10, 0);
        while(x)
        {
            a[x%10]++;
            x/=10;
        }

        for(int j=0; j<10; j++)
        {
            s += a[j]*j;
        }
    }
    return s;
}
int rec(int pos, int sum, int flag)
{
    if(pos == digits.size()) return sum;
    if(dp[pos][sum][flag] != -1)
        return dp[pos][sum][flag];

    // if(!flag) return (sum+45*(digits.size()-pos));
    int rtr=0;
    int k=9;
    if(flag) k=digits[pos];
    // cout<<"K = "<<k<<endl;
    for(int i=0; i<=k; i++)
    {
        int nf=0;
        if(flag && i==digits[pos]) nf=1;
        rtr += rec(pos+1, sum+i, nf);
    }

    return dp[pos][sum][flag]=rtr;
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

    // cout<<"digits size = "<<digits.size()<<endl;
    return rec(0, 0, 1);
}
int main()
{
    int a, b;
    cin>>b;
    while(b--)
    {
        cin>>a;
        int ans = solve(a);
        cout<<"ANS = "<<ans<<endl;
        cout<<"SUM = "<<sum(a)<<endl;
        cout<<endl;
    }
}