#include<bits/stdc++.h>
using namespace std;
    int scc = 0;
    vector<vector<int>> scc_nodes;
    int gid= 0;
    void dfs(int id, vector<int> &id_a, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &lowlink, vector<bool> &onstack, stack<int> &s)
    {
        s.push(id);
        onstack[id] = true;
        id_a[id] = gid;
        lowlink[id] = gid++;

        for(int i=0; i<graph[id].size(); i++)
        {
            if(!visited[graph[id][i]])
            {
                visited[graph[id][i]] = true;
                dfs(graph[id][i], id_a, graph, visited, lowlink, onstack, s);
            }

            if(onstack[graph[id][i]])
                lowlink[id] = min(lowlink[id], lowlink[graph[id][i]]);
        }

        if(lowlink[id] == id_a[id])
        {
            vector<int> temp;
            while(1)
            {
                int x = s.top();
                s.pop();
                onstack[x] = false;
                temp.push_back(x);
                if(x == id) break;
            }

            scc_nodes.push_back(temp);
            scc++;
        }
    }


    void tarjan(vector<vector<int>> graph)
    {
        int n = graph.size();
        vector<int> lowlink(n, INT_MAX);
        vector<bool> onstack(n, false);
        vector<bool> visited(n, false);

        stack<int> s;
        vector<int> id_a(n, -1);
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                dfs(i, id_a, graph, visited, lowlink, onstack, s);
            }
                
        }
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
        graph[t1].push_back(t2);
    }

    cout<<"Graph"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i<<" : ";
        if(!graph[i].size())
            cout<<"null";
        for(int j=0; j<graph[i].size(); j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;
    tarjan(graph);
    cout<<"Number of SCC = "<<scc<<endl;
    for(int i=0; i<scc_nodes.size(); i++)
    {
        for(int j=0; j<scc_nodes[i].size(); j++)
            cout<<scc_nodes[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl;
}