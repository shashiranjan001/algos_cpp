#include<bits/stdc++.h>

using namespace std;
int dp[9][1024][2];
vector<int> digits;

int check(int n)
{
    int s=0;
    for(int i=0; i<n; i++)
    {
        vector<int> v(10,0);
        int x=i;
        while(x)
        {
            v[x%10]++;
            x/=10;
        }
        if(*max_element(v.begin(), v.end())<=1)s++;
    }

    return s;
}
int rec(int pos, int mask, int flag)
{
    cout<<"POS = "<<pos<<" mask = "<<mask<<" flag = "<<flag<<endl;
    if(pos == digits.size()) return 1;
    if(dp[pos][mask][flag] != -1)
        return dp[pos][mask][flag];

    int rtr=0;
    int k=9;
    if(flag) k=digits[pos];
    cout<<"K = "<<k<<endl;

    
    int f=0;
    if(flag && digits[pos]==0) f=1;
    if(mask)
    {
        if(!(mask&1)) rtr += rec(pos+1, mask|1, f);
    }
    else rtr += rec(pos+1, mask, f);
    
    for(int i=1; i<=k; i++)
    {
        // cout<<"Hi\n";
        
        int nf=0;
        if(flag && i==digits[pos]) nf=1;
        cout<<"i = "<<i<<" POS = "<<pos<<" flag = "<<flag<<" nf = "<<nf<<" mask = "<<mask<<endl;
        // cout<<"val = "<<(mask&(1<<i))<<endl;
        if(!(mask&(1<<i)))
        {
            // cout<<"here\n";
            rtr += rec(pos+1, mask|(1<<i), nf);
            cout<<endl;
        }

    }
    //cout<<"----------------------\n";
    return dp[pos][mask][flag]=rtr;
    
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

    for(int i:digits)
        cout<<i<<" ";
    cout<<endl;
    cout<<"digits size = "<<digits.size()<<endl;
    int mask=0;
    return rec(0, mask, 1);
}
int main()
{
    int a, b;
    cin>>a;
    int ans = solve(a);
    cout<<"ANS = "<<ans<<endl;
    cout<<"ANS = "<<check(a)<<endl;
}