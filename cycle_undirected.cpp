#include<bits/stdc++.h>
using namespace std;
template < typename T >
void printVector (const vector < T > & vec) {
	for (const T x : vec) {
		cout << x << " ";
	}
	cout << endl;
}
vector<vector<int>> cycles;
void dfs(int id, int p, vector<vector<int>> &graph, vector<int> &visited, stack<int> &s)
{
    for(int x : graph[id])
    {
        if(visited[x]==1)
        {
            if(x != p)
            {
                vector<int> t;
                stack<int> s2;
                while(s.top() != x)
                {
                    t.push_back(s.top());
                    s2.push(s.top());
                    s.pop();
                }
                t.push_back(s.top());
                cycles.push_back(t);
                while(s2.size())
                {
                    s.push(s2.top());
                    s2.pop();
                }
            }
        }

        else if(visited[x]==0)
        {
            visited[x] =1;
            s.push(x);
            dfs(x,id,graph,visited,s);
            s.pop();
        }
    }

    visited[id] = 2;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> empty;
    vector<vector<int>> graph(n+1, empty);
    int a , b;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int  i=1; i<=n; i++)
    {
        cout<<i<<" : ";
        for(int x:graph[i])
            cout<<x<<" ";
        cout<<endl;
    }

    stack<int> s;
    vector<int> visited(n+1,0);
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            s.push(i);
            dfs(i,-1, graph,visited,s);
        }
    }

    for(auto it : cycles)
    {
        for(int x: it)
            cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}

// 13 14
// 1 2
// 2 3
// 3 4
// 4 7
// 4 6
// 7 8
// 6 5
// 5 3
// 5 9
// 6 10
// 10 11
// 11 13
// 11 12
// 12 13



