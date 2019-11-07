#include <bits/stdc++.h>

using namespace std;
int x, y;
int n;
string s;
unordered_set<string> st;

int rec(int pos, int index, vector<vector<int>> &dp, string sr)
{
    cout<<"POS = "<<pos<<" index = "<<index<<endl;
    if(index == s.length())
    {
        if(pos==y && st.find(sr) == st.end())
        {
            cout<<"sr = "<<sr<<endl;
            st.insert(sr);
            return 1;    
        }
        return 0;
    }
    

    if(dp[pos][index] != -1) return dp[pos][index];
    if(pos == 3 && index == 2) cout<<"HI\n";
    if((pos == 0 && s[index] == 'l') || (pos == n && s[index] == 'r'))
        return dp[pos][index] = rec(pos, index+1, dp, sr);
    
    int ans = 0;
    if(pos == y)
    {
        if(st.find(sr) == st.end())
        {
            cout<<"sr = "<<sr<<endl;
            st.insert(sr);
            ++ans;
        }
    } 

    int new_pos = pos;
    if(s[index] == 'l') new_pos--;
    else new_pos++;


    string temp(1, s[index]);

    
    int a1 = rec(new_pos, index+1, dp, sr+temp);
    int a2 = rec(pos, index+1, dp, sr);
    
    ans += a1+a2;
    return dp[pos][index] = ans; 
}


int main()
{
    cin>>n;
    cin>>s;
    cout<<"N = "<<n<<" S = "<<s<<endl;
    cin>>x>>y;
    cout<<"x = "<<x<<" y = "<<y<<endl;
    vector<vector<int>> dp(n+1, vector<int>(s.length(), -1));
    int ans = rec(x, 0, dp,"");
    cout<<"ANSWER = "<<ans<<endl;
    for(string s : st)
        cout<<s<<" ";
    cout<<endl;

}

// #include<bits/stdc++.h>
// using namespace std;
// int dp[101][100][2];
// int solve(string str, int idx, int flag, int s, int d, int n)
// {
//     if(s > n || s < 0)
//     return 0;
//     int len = str.length();
//     if(idx >= len)
//     return 0;
//     int res = 0;
//     if( (str[idx] == 'l' && flag == 0 ) || ( str[idx] == 'r' && flag) )
//     {
//         int f = 1;
//         if(str[idx] == 'l')
//         f = -1;
//         res = solve(str, idx + 1, flag, s + f, d, n) + solve(str, idx + 1, 1 - flag, s + f, d, n);
//         if(s + f == d)
//         res++;
//     }
//     else
//     {
//         res = solve(str, idx + 1, flag, s, d, n);
//     }
//     dp[idx][s][flag] = res;
//     return res;
// }


// int main()
// {
//     string str;
//     cin >> str;
//     int len = str.length();
//     int n;
//     cin >> n;
//     int s, d;
//     cin >> s >> d;
//     memset(dp, -1, sizeof(dp));
//     int res = solve(str, 0 , 0, s, d, n) + solve(str, 0, 1, s, d, n);
//     cout << res << endl;
// }