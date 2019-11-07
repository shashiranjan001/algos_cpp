#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> floydwarshall(vector<vector<vector<int>>> graph)
{
    int n = graph.size();
    cout<<"n = "<<n<<endl;
    vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
    vector<vector<int>> path(n, vector<int>(n, -1));
    for(int i=0; i<n; i++)
    {
        distance[i][i] = 0;
        path[i][i] = i;
    }

    for(int i=0; i<graph.size(); i++)
    {
        for(int j=0; j<graph[i].size(); j++)
        {
            distance[i][graph[i][j][0]] = graph[i][j][1];
            path[i][graph[i][j][0]] = i;
        }
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                
                if(distance[i][k] == INT_MAX || distance[k][j] == INT_MAX)
                    continue;
                
                if(distance[i][j] > distance[i][k] + distance[k][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    path[i][j] = k;
                    // cout<<"i = "<<i<<" j = "<<j<<" k = "<<k<<endl;
                    // cout<<distance[i][j]<<endl;
                }
            }
        }
    }

    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<n; j++)
    //     {
    //         cout<<distance[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    cout<<"-----------------------------"<<endl;
    vector<vector<vector<int>>> rtr;
    rtr.push_back(distance);
    rtr.push_back(path);
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
    int t1, t2, t3;
    for(int i=0; i<m; i++)
    {
        cin>>t1;
        cin>>t2;
        cin>>t3;
        vector<int> e;
        e.push_back(t2);
        e.push_back(t3);
        graph[t1].push_back(e);
    }

    cout<<"Forward graph"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<" ID = "<<i<<" edges = ";
        for(int j=0; j<graph[i].size(); j++)
            cout<<graph[i][j][0]<<":"<<graph[i][j][1]<<",\t";
        cout<<endl;
    }

    vector<vector<vector<int>>> ans = floydwarshall(graph);
    
    vector<vector<int>> distance = ans[0];
    vector<vector<int>> path = ans[1];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<distance[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"--------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<path[i][j]<<"\t";
        }
        cout<<endl;
    }

    
}



// 4
// 6
// 0 3 15
// 3 0 1
// 0 2 6
// 0 1 3
// 1 2 -2
// 2 3 2