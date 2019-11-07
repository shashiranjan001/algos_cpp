#include<bits/stdc++.h>
using namespace std;

int cnt[10]={0};

int solve(int n, int m)
{
    int ans=0;
    for(int i=n;i<=m;i++){
        for(int j=0;j<10;j++)cnt[j]=0;
        int x=i;while(x){cnt[x%10]++;x/=10;}
        int mx=0;for(int j=0;i<10;j++)mx=max(mx,cnt[j]);
        if(mx<=1)ans++;
    }
    return ans;
}