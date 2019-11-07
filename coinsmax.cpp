#include<bits/stdc++.h>
using namespace std;

int p, q, r, s;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n), d(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    for(int i=0; i<n; i++)
        cin>>d[i];

    int sum;
    cin>>sum;
    vector<vector<vector<int>>> dp2(n, vector<vector<int>>(sum+1, vector<int>(n, 0)));
    vector<vector<int>> dp(n, vector<int>(sum+1,-1));
    cout<<"HEllo\n";
    for(int j=0; j<=sum; j++){
        if(!j) dp[0][j] = 0;
        else{
            if(j%d[0] !=0 ) dp[0][j]= -1;
            else{
                if(j/d[0] <= v[0]){
                    dp[0][j] = j/d[0];
                    dp2[0][j][0] = j/d[0];
                }

                else dp[0][j] = -1;
            }
        }
    }

    
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=sum; j++){
            if(!j) dp[i][j] = 0;
            else{
                if(j>=d[i] && dp[i][j-d[i]] != -1){
                    if(dp2[i][j-d[i]][i]+1 <= v[i]){
                        if(dp[i][j-d[i]] + 1 > dp[i-1][j])
                            dp[i][j] = dp[i][j-d[i]]+1, dp2[i][j] = dp2[i][j-d[i]], dp2[i][j][i]++;
                        else dp[i][j] = dp[i-1][j], dp2[i][j] = dp2[i-1][j];
                    }

                    else dp[i][j] = dp[i-1][j], dp2[i][j] = dp2[i-1][j];
                }

                else dp[i][j] = dp[i-1][j], dp2[i][j] = dp2[i-1][j];
            }
        }
    }
    
    // for(int i=0; i<n; i++)
    // {
    //     cout<<d[i]<<" : ";
    //     for(int j=0; j<=sum; j++)
    //     {
    //         cout<<dp[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    cout<<"Answer = "<<dp[n-1][sum]<<endl;
    
    for(int i=0; i<4; i++)
        cout<<dp2[n-1][sum][i]<<"\t";
    cout<<endl;
    return 0;
}

// 3
// 9 4 4
// 1 2 6
// 9