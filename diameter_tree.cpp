#include<bits/stdc++.h>

using namespace std;
int diameter = 0;
void dfs(vector<vector<int>> &tree, vector<int> &f, vector<int> &g, int v, int p)
{
    vector<int> fs;
    for(int u:tree[v])
    {
        if(u == p) continue;
        dfs(tree, f, g, u, v);
        fs.push_back(f[u]);
    }

    sort(fs.begin(), fs.end());

    if(fs.size()) f[v] = 1 + fs[fs.size()-1];

    if(fs.size()>=2)
    g[v] = 2 + fs[fs.size()-1] + fs[fs.size()-2];

    diameter = max(diameter, max(f[v], g[v]));
}
int main()
{
    int n;
    cin>>n;
    vector<int> empty;
    vector<vector<int>> tree(n, empty);
    int edges, t1, t2;
    cin>>edges;
    for(int i=0; i<edges; i++)
    {
        cin>>t1>>t2;
        tree[t1].push_back(t2);
    }

    for(int i=0; i<n; i++)
    {
        cout<<i<<" : ";
        for(int j=0; j<tree[i].size(); j++)
            cout<<tree[i][j]<<" ";
        cout<<endl;
    }

    vector<int> f(n,0), g(n,0);
    dfs(tree, f, g, 0, -1);

    cout<<"Answer = "<<diameter<<endl;
    return 0;
}