#include<bits/stdc++.h>
using namespace std;

vector<int> father;
int c = 0;
vector<vector<int>> mst_edges;


static bool mysort(vector<int> a, vector<int> b)
{
    return (a[2] <= b[2]);
}


int find_set(int n1)
{
    if(father[n1] == n1)
        return n1;
    
    father[n1] = find_set(father[n1]);
    return father[n1];
}

void unionn(int n1, int n2)
{
    int f1 = find_set(n1);
    int f2 = find_set(n2);

    if(f1 != f2)
    {
        father[f1] = f2;
        c--;
    }

}

void kruskals(int n, vector<vector<int>> &edges)
{
    int st=0;
    vector<int> t(n, 0);
    father = t;
    for(int i=0; i<n; i++)
    {
        father[i] = i;
        c++;
    }

    while(c>1)
    {
        int u = edges[st][0];
        int v = edges[st][1];
        if(find_set(u) != find_set(v))
        {
            unionn(u,v);
            mst_edges.push_back(edges[st]);
        }
        
        st++;
    }
}


int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> edges;
    int t1, t2, t3;
    for(int i=0; i<m; i++)
    {
        cin>>t1;
        cin>>t2;
        cin>>t3;
        vector<int> e;
        e.push_back(t1);
        e.push_back(t2);
        e.push_back(t3);
        edges.push_back(e);
    }


    sort(edges.begin(), edges.end(), mysort);
    for(int i=0; i<m; i++)
    {
        cout<<edges[i][0]<<","<<edges[i][1]<<" : "<<edges[i][2]<<endl;
    }

    kruskals(n, edges);

    for(int i=0; i<mst_edges.size(); i++)
        cout<<char('A' + mst_edges[i][0])<<"---"<<char('A' +mst_edges[i][1])<<" : "<<mst_edges[i][2]<<endl;
    cout<<endl;
}