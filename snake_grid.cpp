#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct ComparisonClass {
    bool operator() (vector<long long> a, vector<long long> b) {
        if(b[0]<a[0]) return true;
        return false;
    }
};

int min_path(vector<vector<int>> &grid, int srcx, int srcy)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<vector<long long>>> dis(n, vector<vector<long long>>(m, vector<long long>(4,INT_MAX)));

    priority_queue<vector<long long>, vector<vector<long long>>, ComparisonClass> pq;
    pq.push({0,0,srcx,srcy});
    dis[srcx][srcy][0]=0;
    // cout<<"here i am\n";
    while(!pq.empty())
    {
        vector<long long> curr = pq.top();
        pq.pop();
        int ori = curr[1], x = curr[2], y=curr[3];
        int d=dis[x][y][ori];
        if(ori==0 && x==n-1 && y==m-2) return dis[x][y][ori];

        if(ori==0)
        {
            if(y<m-2 && grid[x][y+2] == 0)
            {
                // cout<<"here\n";
                if(dis[x][y+1][0] > d+1)
                {
                    dis[x][y+1][0] = d+1;
                    pq.push({d+1,0,x,y+1});
                }
            }

            if(x<n-1 && grid[x+1][y]==0 && grid[x+1][y+1]==0)
            {
                // cout<<"here\n";
                if(dis[x+1][y][0] >d+1)
                {
                    dis[x+1][y][0] = d+1;
                    pq.push({d+1,0,x+1,y});
                }

                if(dis[x][y][1] > d+1)
                {
                    dis[x][y][1] = d+1;
                    pq.push({d+1,1,x,y});
                }
            }

            if(x>0 && grid[x-1][y]==0 && grid[x-1][y+1]==0)
            {
                // cout<<"here\n";
                if(dis[x][y][3]>d+1)
                {
                    dis[x][y][3] = d+1;
                    pq.push({d+1, 3, x,y});
                }
            }
        }

        if(ori==1)
        {
            if(y<m-1 && grid[x][y+1]==0 && grid[x+1][y+1]==0)
            {
                if(dis[x][y+1][1] > d+1)
                {
                    dis[x][y+1][1] = d+1;
                    pq.push({d+1, 1,x,y+1});
                }

                if(dis[x][y][0]>d+1)
                {
                    dis[x][y][0] = d+1;
                    pq.push({d+1, 0,x,y});
                }
            }

            if(x<n-2 && grid[x+2][y]==0)
            {
                if(dis[x+1][y][1] > d+1)
                {
                    dis[x+1][y][1] = d+1;
                    pq.push({d+1, 1, x+1, y});
                }
            }
            if(y>0&&grid[x][y-1]==0 && grid[x+1][y-1]==0)
            {
                if(dis[x][y][2]>d+1)
                {
                    dis[x][y][2] = d+1;
                    pq.push({d+1, 2,x,y});
                }
            }
        }

        if(ori==2)
        {
            if(x<n-1 && grid[x+1][y-1]==0 && grid[x+1][y]==0)
            {
                if(dis[x][y][1]>d+1)
                {
                    dis[x][y][1]=d+1;
                    pq.push({d+1, 1,x,y});
                }
                if(dis[x+1][y][2]>d+1)
                {
                    dis[x+1][y][2] = d+1;
                    pq.push({d+1, 2,x+1,y});
                }
            }

            if(y<m-1&&grid[x][y+1]==0)
            {
                if(dis[x][y+1][2]>d+1)
                {
                    dis[x][y+1][2]=d+1;
                    pq.push({d+1, 2, x, y+1});
                }
            }
            if(x>0&&grid[x-1][y]==0&&grid[x-1][y-1]==0)
            {
                if(dis[x][y][3]>d+1)
                {
                    dis[x][y][3] = d+1;
                    pq.push({d+1, 3, x,y});
                }
            }
        }

        if(ori==3)
        {
            if(y<m-1&&grid[x][y+1]==0 && grid[x-1][y+1]==0)
            {
                if(dis[x][y+1][3]>d+1)
                {
                    dis[x][y+1][3] = d+1;
                    pq.push({d+1, 3, x, y+1});
                }
                if(dis[x][y][0]>d+1)
                {
                    dis[x][y][0] = d+1;
                    pq.push({d+1, 0, x, y});
                }
            }
            if(x<n-1&&grid[x+1][y]==0)
            {
                if(dis[x+1][y][3]>d+1)
                {
                    dis[x+1][y][3] = d+1;
                    pq.push({d+1, 3, x+1,y});
                }
            }

            if(y>0&&grid[x][y-1]==0&&grid[x-1][y-1]==0)
            {
                if(dis[x][y][2] > d+1)
                {
                    dis[x][y][2] = d+1;
                    pq.push({d+1, 2, x,y});
                }
            }
        }
        
    }
    return dis[n-1][m-2][0];
}


int main()
{
    int n, m;
    cin>>n>>m;
    cout<<"n = "<<n<<" m = "<<m<<endl;
    vector<vector<int>> grid(n, vector<int>(m,0));
    // cout<<"Hi\n";
    int t;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {   cin>>t; grid[i][j]=t;}
    }

    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m; j++)
    //         cout<<grid[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<"--------------\n";


    int res = min_path(grid, 0, 0);
    cout<<res<<endl;
}

// 6 6
// 0 0 0 0 0 1 
// 1 1 0 0 1 0 
// 0 0 0 0 1 1 
// 0 0 1 0 1 0 
// 0 1 1 0 0 0 
// 0 1 1 0 0 0
