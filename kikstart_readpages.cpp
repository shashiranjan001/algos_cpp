#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int l=1; l<=t; l++)
    {
        int n, m, q;
        cin>>n>>m>>q;
        int torn[m], reader[q];
        for(int i=0; i<m; i++)
            cin>>torn[i];
        for(int i=0; i<q; i++)
            cin>>reader[i];

        
        unordered_map<int, int> mp;
        for(int j=0; j<m; j++)
        {
            for(int i=1; i<= sqrt(torn[j]); i++)
            {
                if(torn[j]%i==0)
                {
                    if(torn[j]/i == i)
                        mp[i]++;
                    else
                    {
                        mp[i]++;
                        mp[torn[j]/i]++;
                    }
                }
            }
        }

        int sum = 0;
        for(int i=0; i<q; i++)
        {
            sum += n/reader[i];
            if(mp.find(reader[i]) != mp.end())
                sum -= mp[reader[i]];
        }

        cout<<"Case #"<<l<<": "<<sum<<endl;
    }
    return 0;
}