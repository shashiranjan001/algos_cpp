# include <bits/stdc++.h>

using namespace std;

void lps(string s, int l, int h, vector<vector<int> > &dp)
{
    cout<<"l = "<<l<<endl;
    cout<<"h = "<<h<<endl;
    if(l==h-1)
    {
        if(s[l] == s[h])
        {
            dp[l][h] = 2;
            cout<<"dp["<<l<<"]["<<h<<"] = "<<dp[l][h]<<endl;
            return;
        }
        
        else
        {
            dp[l][h] = 0;
            cout<<"dp["<<l<<"]["<<h<<"] = "<<dp[l][h]<<endl;
            return;
        }
    }
    if(l==h)
    {
        dp[l][h] = 1;
        cout<<"dp["<<l<<"]["<<h<<"] = "<<dp[l][h]<<endl;
        return;
    }
    
    
    
    
    if(s[l] == s[h])
    {
        if(dp[l+1][h-1] == -1) 
            lps(s, l+1, h-1, dp);

        if(dp[l+1][h-1])
            dp[l][h] = dp[l+1][h-1]+2;

        else
            dp[l][h] = 0;
    }

    else
    {
        if(dp[l+1][h] == -1) 
            lps(s, l+1, h, dp);
        if(dp[l][h-1] == -1) 
            lps(s, l, h-1, dp);
    }

    dp[l][h] = max(dp[l][h], max(dp[l][h-1], dp[l+1][h]));
    cout<<"dp["<<l<<"]["<<h<<"] = "<<dp[l][h]<<endl;
    return;
}



int main()
{
    string s;
    cin>>s;

    vector<vector<int> > dp(s.length(), vector<int>(s.length(),-1));
    lps(s, 0, s.length()-1, dp);

    for(int i=0; i<s.length(); i++)
    {
        for(int j=0 ;j<s.length(); j++)
            cout<<dp[i][j]<<"\t";
        cout<<endl;
    }

    int maxx = 0, low;
    for(int i=0; i<s.length(); i++)
    {
        for(int j=0 ;j<s.length(); j++)
        {
            if(dp[i][j] > maxx)
            {
                maxx = dp[i][j];
                low = i;
            }
        }
        cout<<endl;
    }

    cout<<s.substr(low, maxx)<<endl;
    // vector<vector<int> > dp(s.length(), vector<int>(s.length(),0));
    // int low, maxx=0;
    
    // // lps(s,0, s.length()-1, dp);

    // for(int i=0; i<s.length(); i++)
    // {
    //     dp[i][i] = 1;
    //     if(dp[i][i] > maxx)
    //     {
    //         maxx = dp[i][i];
    //         low = i;
    //     }

    // }
    
    // for(int i=0; i<s.length()-1; i++)
    // {
    //     if(s[i] == s[i+1])
    //         dp[i][i+1] =2;
    //     else
    //         dp[i][i+1] = 0;

    //     int j = i+1;
    //     if(dp[i][j] > maxx)
    //     {
    //         maxx = dp[i][j];
    //         low = i;
    //     }
    // }

    // for(int l=3; l<=s.length(); l++)
    // {
    //     for(int i=0; i+l-1<s.length(); i++)
    //     {
    //         int j = i+l-1;
    //         if(s[i] == s[j])
    //         {
    //             if(dp[i+1][j-1])
    //                 dp[i][j] = dp[i+1][j-1] + 2; 
    //         }

    //         else
    //             dp[i][j] = 0;

    //         if(dp[i][j] > maxx)
    //         {
    //             maxx = dp[i][j];
    //             low = i;
    //         }
    //     }
    // }
    
    // for(int i=0; i<s.length(); i++)
    // {
    //     for(int j=0; j<s.length(); j++)
    //         cout<<dp[i][j]<<"\t";
    //     cout<<endl;
    // }
    
    // cout<<s.substr(low, maxx)<<endl;
    
    // low =0;
    // high =0;
    return 0;
}