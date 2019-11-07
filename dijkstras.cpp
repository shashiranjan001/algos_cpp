#include<bits/stdc++.h>
using namespace std;




vector<int> dijkstras(vector<vector<vector<int>>> graph, int src)
{
    int n = graph.size();
    vector<int> d(n, INT_MAX);
    set<pair<int, int>> heap;
    heap.insert(make_pair(0, src));
    d[src] = 0;
    while(heap.size())
    {
        pair<int, int> top = *heap.begin();
        heap.erase(heap.begin());

        int node = top.second;

        for(int i=0; i<graph[node].size(); i++)
        {
            int curr_node = graph[node][i][0];
            int wt = graph[node][i][1];
            if(d[curr_node] > d[node]+wt)
            {
                if(d[curr_node] != INT_MAX)
                    heap.erase(heap.find(make_pair(d[curr_node], curr_node)));

                heap.insert(make_pair(d[node]+wt, curr_node));
                d[curr_node] = d[node] + wt;
            }
        }
    }
    return d;
}


int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> t;
    vector<vector<vector<int>>> graph(n, t);
    int t1, t2, t3;
    for(int i=0; i<m; i++)
    {
        cin>>t1;
        cin>>t2;
        cin>>t3;
        vector<int> e, f;
        e.push_back(t2);
        e.push_back(t3);
        f.push_back(t1);
        f.push_back(t3);
        graph[t1].push_back(e);
        graph[t2].push_back(f);
    }

    cout<<"Forward graph"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<" ID = "<<i<<" edges = ";
        for(int j=0; j<graph[i].size(); j++)
            cout<<graph[i][j][0]<<":"<<graph[i][j][1]<<",\t";
        cout<<endl;
    }

    vector<int> dis= dijkstras(graph, 0);
    for(int i=0; i<n; i++)
        cout<<(char)('A'+i)<<" : "<<dis[i]<<endl;
    return 0;
}

// 6
// 7
// 0 1 5
// 0 3 9
// 1 2 2
// 2 3 3
// 0 4 2
// 4 5 3
// 5 3 2