#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ratio;
    cin>>n>>ratio;
    vector<pair<int, int>> v;
    int a,b;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        v.push_back({a,b});
    }

    int mid = n/2;
    // vector<pair<int, int>> set1(1<<mid);

    unordered_map<int, unordered_set<int>>mp;
    for(int i=0; i<(1<<(n-mid)); i++)
    {
        int p=0,f=0;
        for(int j=0; j<n-mid; j++)
        {
            if(i&(1<<j))
            {
                p += v[j+mid].first;
                f += v[j+mid].second;
            }
        }

        mp[p].insert(f);
    }


    int answer = 0;
    for(int i=0; i<(1<<mid); i++)
    {
        int p=0,f=0;
        for(int j=0; j<mid; j++)
        {
            if(i&(1<<j))
            {
                p += v[j].first;
                f += v[j].second;
            }
        }

        int m = ratio-(p%ratio);
        int increment =0;
        while(p+m+increment <= 20)
        {
            int x = m+increment;
            if(mp.find(x) != mp.end())
            {
                int y = (p+x)/ratio - f;
                if(mp[x].find(y) != mp[x].end())
                {
                    answer = 1;
                    break;
                }
            }
            increment += ratio;
        }

        if(answer) break;
    }

    if(answer) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}