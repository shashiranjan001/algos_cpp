// Bridges.cpp

#include<bits/stdc++.h>
using namespace std;
int gtime;
vector<vector<int>> edges;
void dfs(int id, vector<int> &p, vector<int> &low, vector<int> &disc, vector<int> &visited, vector<vector<int>> &graph)
{
    low[id]= gtime;
    disc[id] = gtime++;

    for(int v : graph[id])
    {
        if(visited[v] == 0)
        {
            p[v] = id;
            visited[v] =1;
            dfs(v, p,low,disc,visited,graph);
            
            low[id] = min(low[id], low[v]);
            if(low[v] > disc[id])
            {
                edges.push_back({id, v});
                edges.push_back({v, id});
            }
        }

        if(p[id] != v)
        {
            low[id] = min(low[id], disc[v]);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> t;
    vector<vector<int>> graph(n, t), ed(m,t);
    set<vector<int>> s;
    int t1, t2, t3;
    for(int i=0; i<m; i++)
    {
        cin>>t1;
        cin>>t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
       s.insert({t1,t2});
    }

    cout<<"Forward graph"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<" ID = "<<(char)('A'+i)<<" : ";
        for(int j=0; j<graph[i].size(); j++)
            cout<<(char)('A'+graph[i][j])<<" ";
        cout<<endl;
    }

    vector<int> p(n, -1);
    vector<int> low(n,0);
    vector<int> disc(n,0);
    vector<int> visited(n,0);

    gtime=0;
    for(int i=0; i<n; i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;
            dfs(i, p, low, disc, visited, graph);
        } 
    }

    vector<vector<int>> rtr;
    for(auto v : edges)
    {
        if(s.find(v) != s.end())
            rtr.push_back(v);
    }

    for(auto v : rtr)
        cout<<(char)('A'+v[0])<<", "<<(char)('A'+v[1])<<endl;

    unordered_set<int> artipoints;
    for(auto v:rtr)
    {
        if(graph[v[0]].size() > 1)
            artipoints.insert(v[0]);
        if(graph[v[1]].size() > 1)
            artipoints.insert(v[1]);
    }

    for(int i : artipoints)
        cout<<(char)('A' + i)<<" ";
    cout<<endl;
    return 0;
}