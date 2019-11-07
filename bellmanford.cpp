#include<bits/stdc++.h>
using namespace std;


map<int, vector<int>> bellmanford(int n, vector<vector<int>> edges)
{
   // yo!yoyoyoy
    for(int i=0; i<n; i++)
        rtr[i] = t;

    rtr[0][0] = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int e =0; e<edges.size(); e++)
        {
            int u = edges[e][0];
            int v = edges[e][1];
            int wt = edges[e][2];

            if(rtr[v][0] > rtr[u][0] + wt)
            {
                rtr[v][0] = rtr[u][0] + wt;
                rtr[v][1] = u;
            }
        }
    }


    for(int e =0; e<edges.size(); e++)
    {
        int u = edges[e][0];
        int v = edges[e][1];
        int wt = edges[e][2];

        if(rtr[v][0] > rtr[u][0] + wt)
        {
            cout<<"Negative Weight CYCLE Exists\n";
        }
    }

    return rtr;
}


int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> t;
    vector<vector<vector<int>>> graph(n, t);
    vector<vector<int>> edges;
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
        f.push_back(t2);
        f.push_back(t3);
        graph[t1].push_back(e);
        edges.push_back(f);
    }

    cout<<"Forward graph"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<" ID = "<<i<<" edges = ";
        for(int j=0; j<graph[i].size(); j++)
            cout<<graph[i][j][0]<<":"<<graph[i][j][1]<<",\t";
        cout<<endl;
    }

    map<int, vector<int>> ans = bellmanford(n, edges);
    for(auto it = ans.begin(); it != ans.end(); it++)
    {
        cout<<"NODE"<<it->first<<" Dist = "<<it->second[0]<<" Parent = "<<it->second[1]<<endl;
    }
    return 0;
}



// 5
// 7
// 0 1 4
// 0 2 5
// 1 2 -3
// 2 4 4
// 0 3 8
// 3 4 2
// 4 3 1