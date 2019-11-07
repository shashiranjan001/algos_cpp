#include<bits/stdc++.h>

using namespace std;

int LCA;

pair<bool, bool> dfs(int id, int p, vector<vector<int>> &tree, int a, int b)
{
    int a1 = false, a2=false;
    int f=1;
    for(int i:tree[id])
    {
        if(i!=p)
        {
            pair<int, int> p=dfs(i,id, tree, a, b);
            if(p.first==true && p.second==true) f=0;
            a1 |=p.first;
            a2 |=p.second;
        }
    }

    if(id==a) a1 = true;
    if(id==b) a2 = true;

    if(f && a1 && a2) LCA =id;

    return{a1,a2};
}

int main()
{
    int n;
    cin>>n;
    vector<int> empty;
    vector<vector<int>> tree(n+1, empty);
    int e, p1, q1;
    cin>>e;
    cout<<"E = "<<e<<endl;
    for(int i=0; i<e; i++)
    {
        cin>>p1>>q1;
        tree[p1].push_back(q1);
    }

    for(int i=1; i<=n; i++)
    {
        cout<<i<<" : ";
        for(int j=0; j<tree[i].size(); j++)
            cout<<tree[i][j]<<" ";
        cout<<endl;
    }
    
    int a, b;
    cin>>a>>b;
    int root = 1;
    pair<bool, bool> p =dfs(1, -1, tree, a, b);

    cout<<"LCA = "<<LCA<<endl;
}