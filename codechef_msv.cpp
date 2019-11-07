#include<bits/stdc++.h>

using namespace std;

int main()
{
    int l=1, h = 10e4;
    int t,n,tt;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            cin>>tt;
            v.push_back(tt);
        }

        vector<int> empty;
        vector<vector<int>> pos(h+1, empty);
        for(int i=0; i<v.size(); i++)
        {
            pos[v[i]].push_back(i);
        }

        vector<vector<int>> divisible_posses(h+1, empty);
        for(int i=1; i<=h; i++)
        {
            for(int j=i; j<=h; j+=i)
            {                for(int k=0; k<pos[j].size(); k++) 
                    divisible_posses[i].push_back(pos[j][k]);
            }
        }

        for(int i=1; i<=h; i++)
            sort(divisible_posses[i].begin(), divisible_posses[i].end());

        int maxx=INT_MIN;
        for(int i=0; i<v.size(); i++)
        {
            int lo = lower_bound(divisible_posses[v[i]].begin(),divisible_posses[v[i]].end(), i)-divisible_posses[v[i]].begin();
            maxx = max(maxx, lo);
        }

        cout<<maxx<<endl;
    }

}
