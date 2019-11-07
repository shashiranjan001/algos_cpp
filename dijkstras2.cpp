#include<bits/stdc++.h>
using namespace std;


struct ComparisonClass {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return (a.first>b.first);
    }
};

vector<long long> dijkstras(vector<vector<vector<int>>> &graph, int src)
{
    int n = graph.size();
    vector<long long> dis(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, ComparisonClass> pq;

    pq.push({0,src});
    dis[src]=0;
    while(!pq.empty())
    {
        pair<int,int> curr = pq.top();
        pq.pop();
        for(auto c:graph[curr.second])
        {
            int id = c[0];
            int dst = c[1];
            if(dis[id] > dis[curr.second]+dst)
            {
                dis[id] = dis[curr.second]+dst;
                pq.push({dis[id], id});
            }
        }
    }

    return dis;
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

    vector<long long> dis= dijkstras(graph, 0);
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











