#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &graph, vector<vector<bool>> &visited)
{
    int n = graph.size();
    // cout<<"i = "<<i<<" j = "<<j<<endl;
    if(i>=0 && j>=0 && i<n && j<n)
    {
        if(graph[i][j] && !visited[i][j])
        {
            visited[i][j] = true;
            dfs(i, j-1, graph, visited);
            dfs(i-1, j, graph, visited);
            dfs(i, j+1, graph, visited);
            dfs(i+1, j, graph, visited);
            
        }
    }
}

int regionsBySlashes(vector<string>& grid) {

    int n = grid.size();
    vector<vector<int>> flag;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        int j = 0;
        while(j<grid[i].length())
        {
            if(grid[i][j] == '/')
            {
                temp.push_back(2);
                j++;
            }
            else if(grid[i][j] == '\\')
            {
                temp.push_back(1);
                j++;
            }

            else
            {
                temp.push_back(0);
                j++;
            }
        }
        flag.push_back(temp);
    }

    vector<vector<int>> graph(3*n, vector<int>(3*n, 1));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(flag[i][j] == 1)
            {
                graph[3*i+0][3*j+0] = 0;
                graph[3*i+1][3*j+1] = 0;
                graph[3*i+2][3*j+2] = 0;
            }

            else if(flag[i][j] == 2)
            {
                graph[3*i+0][3*j+2] = 0;
                graph[3*i+1][3*j+1] = 0;
                graph[3*i+2][3*j+0] = 0;
            }
        }
    }
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<n; j++)
    //     {
    //         cout<<flag[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;

    // for(int i=0; i<3*n; i++)
    // {
    //     for(int j=0; j<3*n; j++)
    //     {
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;
    

    int c=0;
    vector<vector<bool>> visited(3*n, vector<bool>(3*n,false));
    for(int i=0; i<3*n; i++)
    {
        for(int j=0; j<3*n; j++)
        {
            if(graph[i][j] && !visited[i][j])
            {
                // visited[i][j] = true;
                dfs(i, j, graph, visited);
                c++;
            }
        }
    }
    return c;
}

int main()
{
    vector<string> v ={"/\\/", "\\/\\", "//\\"};
    int ans = regionsBySlashes(v);
    cout<<"ANS = "<<ans<<endl;
    return 0;
}