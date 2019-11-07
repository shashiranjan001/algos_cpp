#include<bits/stdc++.h>
using namespace std;


int min_rec(vector<int> x, vector<int> y)
{
    int n = x.size();
    map<pair<int, int>, set<int>> mp;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(x[i]==x[j])
            {
                mp[{max(y[i], y[j]), min(y[i], y[j])}].insert(x[i]);
            }
        }
    }


    int min_area = INT_MAX;
    for(auto it = mp.begin(); it !=mp.end(); it++)
    {
        int h = (it->first.first)-(it->first.second);
        vector<int> xs(it->second.begin(), it->second.end());
        for(int i=1; i<xs.size(); i++)
        {
            min_area = min(min_area, (xs[i]-xs[i-1])*h);
        }
    }

    return min_area;
}

int main()
{
    vector<int> x{1,1,2,2,3,3,4,4};
    vector<int> y{0,3,1,8,1,8,1,3};

    cout<<min_rec(x,y)<<endl;
    return 0;    
}