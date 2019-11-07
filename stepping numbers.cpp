#include<bits/stdc++.h>
using namespace std;


    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) 
    {
        // write your code here
        int maxx= INT_MIN;
        map<vector<int>, int> mp;
        
        int i=0;
        for(auto it : edges)
        {
            maxx = max(maxx, it[0]);
            maxx = max(maxx, it[1]);
            mp[it] = ++i;
        }
        vector<int> empty;
        vector<vector<int>> graph(maxx+1, empty);
        
        for(auto it : edges)
            graph[it[0]].push_back(it[1]);
        
        int i=0;
        for(auto it:graph)
        {
            cout<<i<<" : ";
            for(auto itt:it)
                cout<<itt<<" ";
            cout<<endl;
            i++;
        }
        cout<<"--------------------\n";
        vector<int> visited(maxx+1, 0);
        vector<int> parent(maxx+1, 0);
        for(int i=1; i<=maxx; i++)
        {
            if(visited[i] == 0)
            {
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int curr = q.top();
                    q.pop();
                    for(auto j:graph[curr])
                    {
                        if(parent[j] != 0)
                        {
                            vector<int> v1{curr, j};
                            vector<int> v2{parent[j], j};
                            if(mp[v1] > mp[v2])
                                return v1;
                            return v2;
                        }
                        
                        parent[j] = curr;
                        q.push(j);
                        visited[j] =1;
                    }
                }
            }
        }
    }


    void dfs(int id, vector<vector<int>> &graph, vector<int> &visited, set<vector<int>> &s)
    {
        for(auto it:graph[id])
        {
            if(visited[it] == 0)
            {
                visited[it] =1;
                dfs(it, graph, visited, s);
            }
            
            if(visited[it] == 1)
            {
                s.insert({id, it});
                s.insert({it, id});
            }
        }
    }
        
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        // write your code here
        int maxx= INT_MIN;
        for(auto it : edges)
        {
            maxx = max(maxx, it[0]);
            maxx = max(maxx, it[1]);
        }
        vector<int> empty;
        vector<vector<int>> graph(maxx+1, empty);
        
        for(auto it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        int i=0;
        for(auto it:graph)
        {
            cout<<i<<" : ";
            for(auto itt:it)
                cout<<itt<<" ";
            cout<<endl;
            i++;
        }
        cout<<"--------------------\n";
        vector<int> visited(maxx+1, 0);
        set<vector<int>> s;
        for(int i=1; i<=maxx; i++)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                dfs(i, graph, visited, s);
            }
        }
        
        reverse(edges.begin(), edges.end());
        for(auto it:edges)
        {
            if(s.find(it) != s.end())
                return it;
        }
        
    }


void dfs(int i, int low, int high, set<int> &v)
{
    if(i>high) return;
    if(i>=low) v.insert(i);
    int d = i%10;
    if(d==0) dfs(i*10+1, low, high, v);
    else if(d==9) dfs(i*10+8, low, high, v);
    else
    {
        dfs(i*10+d+1, low, high, v);
        dfs(i*10+d-1, low, high, v);
    }
}
vector<int> countSteppingNumbers(int low, int high) {
    set<int> v;
    vector<int> rtr;
    for(int i=0; i<9; i++)
        dfs(i, low, high, v);
    for(auto it:v)
        rtr.push_back(it);
    return rtr;
}

int main()
{
    int l=56, h=5210;
    vector<int> v=countSteppingNumbers(l,h);

    for(auto x:v) cout<<x<<" ";
    cout<<endl;
}

