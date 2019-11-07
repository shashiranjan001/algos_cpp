#include<bits/stdc++.h>

using namespace std;

int main()
{
    int l=1, h = 10e4;
    vector<int> v{-1,2,6,9,10,8};
    vector<int> empty;
    vector<vector<int>> pos(h+1, empty);
    for(int i=1; i<v.size(); i++)
    {
        pos[v[i]].push_back(i);
    }
    vector<vector<int>> divisible_posses(h+1, empty);
    for(int i=1; i<=h; i++)
    {
        for(int j=i; j<=h; j+=i)
        {
            for(int k=0; k<pos[j].size(); k++) 
                divisible_posses[i].push_back(pos[j][k]);
        }
    }


    for(int i=1; i<=h; i++)
        sort(divisible_posses[i].begin(), divisible_posses[i].end());

    int q = 4, id, d;
    for(int i=0; i<q; i++)
    {
        cin>>id>>d;
        int lo = divisible_posses[d].end() - lower_bound(divisible_posses[d].begin(),divisible_posses[d].end(), id);
        cout<<lo<<endl;
    }

}
