#include<bits/stdc++.h>

using namespace std;
int rec2(int id, int p, vector<vector<int>> &graph, vector<vector<int>> &dp1, vector<vector<int>> &dp2, vector<int> &real, vector<int> &neww);


int rec1(int id, int p, vector<vector<int>> &graph, vector<vector<int>> &dp1, vector<vector<int>> &dp2, vector<int> &real, vector<int> &neww)
{
    if(dp1[id][0] == -1)
    {
        if(real[id] == neww[id])
        {
            int s =0;
            for(int x : graph[id])
            {
                if(x!=p)
                {
                    int r = rec1(x, id, graph, dp1, dp2, real, neww);
                    s += r;
                }
            }

            dp1[id][0] = s;
        }

        else
        {
            dp1[id][0] = INT_MAX;
        }
    }

    if(dp1[id][1] == -1)
    {
        if(real[id] == neww[id])
        {
            dp1[id][1] = INT_MAX;
        }

        else
        {
            int s=1;
            for(int x:graph[id])
            {
                if(x!=p)
                {
                    int r = rec1(x, id,graph, dp1, dp2, real, neww);
                    s += r;
                }
            }

            dp1[id][1] = s;
        }
    }

    if(dp1[id][2] == -1)
    {
        if(real[id] == neww[id])
        {
            dp1[id][2] = INT_MAX;
        }

        else
        {
            int s=1;
            for(int x:graph[id])
            {
                if(x!=p)
                {
                    int r = rec2(x,id,graph, dp1, dp2, real, neww);
                    s += r;
                }
            }

            dp1[id][2] = s;
        }
    }

    return min(dp1[id][0], min(dp1[id][1], dp1[id][2]));
}

int rec2(int id, int p, vector<vector<int>> &graph, vector<vector<int>> &dp1, vector<vector<int>> &dp2, vector<int> &real, vector<int> &neww)
{
    if(dp2[id][0] == -1)
    {
        if(real[id] != neww[id])
        {
            int s =0;
            for(int x : graph[id])
            {
                if(x!=p)
                {
                    int r = rec2(x, id, graph, dp1, dp2, real, neww);
                    s += r;
                }
            }

            dp2[id][0] = s;
        }

        else
        {
            dp2[id][0] = INT_MAX;
        }
    }

    if(dp2[id][1] == -1)
    {
        if(real[id] != neww[id])
        {
            dp2[id][1] = INT_MAX;
        }

        else
        {
            int s=1;
            for(int x:graph[id])
            {
                if(x!=p)
                {
                    int r = rec2(x,id,graph, dp1, dp2, real, neww);
                    s += r;
                }
            }

            dp2[id][1] = s;
        }
    }

    if(dp2[id][2] == -1)
    {
        if(real[id] != neww[id])
        {
            dp2[id][2] = INT_MAX;
        }

        else
        {
            int s=1;
            for(int x:graph[id])
            {
                if(x!=p)
                {
                    int r = rec1(x,id, graph, dp1, dp2, real, neww);
                    s += r;
                }
            }

            dp2[id][2] = s;
        }
    }

    return min(dp2[id][0], min(dp2[id][1], dp2[id][2]));
}



int main()
{
    int n;
    cin>>n;
    vector<int> empty;
    int a,b;
    vector<vector<int>> graph(n+1, empty);
    for(int i=0; i<n-1; i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
    {
        cout<<i<<" : ";
        for(int j : graph[i])
            cout<<j<<" ";
        cout<<endl;
    }

    vector<vector<int>> dp1(n+1,vector<int>(3,-1));
    vector<vector<int>> dp2(n+1,vector<int>(3,-1));

    vector<int> real(n+1), neww(n+1);
    for(int i=1; i<=n; i++)
    {
        cin>>neww[i];
    }

    for(int i=1; i<=n; i++)
    {
        cin>>real[i];
    }

    int ans = rec1(1, -1, graph, dp1, dp2, real, neww);
    // vector<int> a2 = rec2(1, graph, dp1, dp2, real, neww);

    cout<<"\n\nDP1\n";
    for(int i=1; i<=n; i++)
        cout<<i<<" : "<<dp1[i][0]<<" "<<dp1[i][1]<<" "<<dp1[i][2]<<endl;
    
    cout<<"\n\nDP2\n";
    for(int i=1; i<=n; i++)
        cout<<i<<" : "<<dp2[i][0]<<" "<<dp2[i][1]<<" "<<dp2[i][2]<<endl;

    
   
    cout<<"ANS = "<<ans<<endl;
    return 0;
}


// 7
// 3 7
// 1 7
// 7 4
// 3 2
// 1 6
// 5 1
// 1 0 1 1 1 1 0
// 0 0 1 0 1 0 1
    