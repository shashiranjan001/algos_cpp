#include <bits/stdc++.h>

using namespace std;
unordered_set<string> words;
vector<string> rec(int id, string s, vector<vector<string>> &dps)
{
    if(!s.length())
    {
        vector<string> rtr(1, "");
        return rtr;
    }

    if(dps[id].size() != 0)
        return dps[id];
    
    vector<string> rtr;
    string space(" ");
    for(int i=1; i<=s.length(); i++)
    { 
        
        if(words.count(s.substr(0,i)))
        {
            vector<string> ans = rec(i, s.substr(i), dps);
            for(string str : ans)
                rtr.push_back(s.substr(0,i) + space + str);
        }
    }

    return rtr;
}

int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;

    string t;
    for(int i=0; i<n; i++)
    {
        cin>>t;
        words.insert(t);
    }

    // for(string s : words)
    //     cout<<s<<endl;
    vector<string> empty;
    vector<vector<string>> dps(n, empty);
    vector<string> rtr = rec(0,s,dps);

    for(int i=0; i<rtr.size(); i++)
        cout<<rtr[i]<<endl;
}