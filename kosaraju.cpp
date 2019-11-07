#include<bits/stdc++.h>
using namespace std;


void dfs(int id, vector<vector<int>> &adj, stack<int> &s, unordered_set<int> &visited)
{
    for(int i=0; i<adj[id].size(); i++)
    {
        if(visited.find(adj[id][i]) == visited.end())
        {
            visited.insert(adj[id][i]);
            dfs(adj[id][i], adj, s, visited);
        }
    }
    
    s.push(id);
}

void dfs2(int id, vector<vector<int>> &rev, unordered_set<int> &visited)
{
    for(int i=0; i<rev[id].size(); i++)
    {
        if(visited.find(rev[id][i]) == visited.end())
        {
            visited.insert(rev[id][i]);
            dfs2(rev[id][i], rev, visited);
        }
    }
}


int kosaraju(int V, vector<vector<int>> &adj)
{
    cout<<"Forward graph"<<endl;
    for(int i=0; i<V; i++)
    {
        cout<<" ID = "<<i<<" edges = ";
        for(int j=0; j<adj[i].size(); j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
    
    cout<<endl<<endl;
    stack<int> s;
    unordered_set<int> visited;
    
    for(int i=0; i<V; i++)
    {
        if(visited.find(i) == visited.end())
        {
            visited.insert(i);
            dfs(i, adj, s,visited);
        }
    }
    
    
    
    
    vector<vector<int>> rev(V, vector<int>(0));
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            rev[adj[i][j]].push_back(i);
        }
    }
    
    
    
    cout<<"Transpose graph"<<endl;
    for(int i=0; i<V; i++)
    {
        cout<<" ID = "<<i<<" edges = ";
        for(int j=0; j<rev[i].size(); j++)
            cout<<rev[i][j]<<" ";
        cout<<endl;
    }
    
    cout<<endl<<endl;
    
    
    unordered_set<int> v2;
    int c=0;
    while(!s.empty())
    {
        int x = s.top();
        s.pop();
        if(v2.find(x) == v2.end())
        {
            dfs2(x, rev, v2);
            c++;
        }
    }
    
    return c;
}



int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> t;
    vector<vector<int>> graph(n, t);
    int t1, t2;
    for(int i=0; i<m; i++)
    {
        cin>>t1;
        cin>>t2;
        cout<<"HELLO\n";
        graph[t1].push_back(t2);
    }

    cout<<"Forward graph"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<" ID = "<<i<<" edges = ";
        for(int j=0; j<graph[i].size(); j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }

    int ans = kosaraju(n, graph);
    cout<<"Answer = "<<ans<<endl;
    return 0;
}