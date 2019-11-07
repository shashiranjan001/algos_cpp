#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n+1,0);
    for(int i=1; i<=n; i++)
        cin>>v[i];

    vector<int> visited(n+1,0);
    vector<int> cycles;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            int sz = 1;
            visited[i]=1;
            int j = v[i];
            while(!visited[j])
            {
                sz++;
                visited[j] =1;
                j = v[j];
            }

            cycles.push_back(sz);
        }
    }
    for(int i:cycles)
        cout<<i<<" ";
    cout<<endl;
    int ans;
    if(cycles.size()==1)
    {
        if(cycles[cycles.size()-1]>1)
            ans = cycles[cycles.size()-1]/2;
    }
        
    else
    {
        sort(cycles.begin(), cycles.end());
        if(cycles[cycles.size()-1] == cycles[cycles.size()-2])
            ans = -1;
        else
            ans = max(cycles[cycles.size()-1]/2, cycles[cycles.size()-2]);
    }
    cout<<"ANSWER = "<<ans<<endl;
    return 0;
}