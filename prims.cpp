#include<bits/stdc++.h>
using namespace std;




vector<vector<int>> prims(vector<vector<vector<int>>> graph)
{
    int n = graph.size();
    vector<int> d(n, INT_MAX);
    vector<bool> exitheap(n, false);
    set<pair<int, int>> heap;

    unordered_map<int, vector<int>> mp;
    vector<vector<int>> edges;

    heap.insert(make_pair(0, 0));
    d[0] = 0;
    mp[0].push_back(-1);
    while(heap.size())
    {
        pair<int, int> top = *heap.begin();
        heap.erase(heap.begin());
        int node = top.second;
        exitheap[node] = true;

        if(mp[node][0] != -1)
            edges.push_back(mp[node]);



        for(int i=0; i<graph[node].size(); i++)
        {
            int curr_node = graph[node][i][0];
            int wt = graph[node][i][1];
            if(!exitheap[curr_node] && d[curr_node] > wt)
            {
                if(d[curr_node] != INT_MAX)
                    heap.erase(heap.find(make_pair(d[curr_node], curr_node)));

                heap.insert(make_pair(wt, curr_node));
                d[curr_node] = wt;

                vector<int> temp;
                temp.push_back(node);
                temp.push_back(curr_node);
                temp.push_back(wt);
                mp[curr_node] = temp;
            }
        }

        cout<<node<<" heap _size = "<<heap.size()<<endl;
    }
    return edges;
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

    vector<vector<int>> dis= prims(graph);
    for(int i=0; i<dis.size(); i++)
        cout<<(char)('A'+dis[i][0])<<","<<(char)('A'+dis[i][1])<<" : "<<dis[i][2]<<endl;
    return 0;
}



// 6
// 9
// 0 1 3
// 0 3 1
// 1 3 3
// 3 2 10
// 1 2 1
// 3 4 6
// 2 4 5
// 2 5 4
// 4 5 2