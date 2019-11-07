#include<bits/stdc++.h>

using namespace std;


int rec(string s, unordered_map<string, int> &mp, vector<int> &arr)
{
    vector<int> a1=arr;
    vector<int> a2 =arr;
    string s2=s, s1= s;
    if(s.length() <=2) return 0;

    if(mp.find(s) != mp.end())
        return mp[s];

    int cost1=0;
    if(arr[s1[0]-'a'] == 1)
    {
        cost1++;
        char c = s1[0];
        s1[0] = s1[1];
        s1[1] = c;
    }

    int k =s1.size()-1;
    while(s1[k] != s1[0]) k--;
    for(int i=k; i<s1.size()-1; i++)
    {
        char c = s1[i];
        s1[i] = s1[i+1];
        s1[i+1] = c;
        cost1++;
    }

    a1[s1[0]-'a'] -= 2;
    cost1 += rec(s1.substr(1, s1.size()-2), mp, a1);

    int cost2=0;
    int sz = s2.size();
    if(arr[s2[sz-1]-'a'] == 1)
    {
        cost2++;
        char c = s2[sz-1];
        s2[sz-1] = s2[sz-2];
        s2[sz-2] = c;
    }

    k =0;
    while(s2[k] != s2[sz-1]) k++;
    for(int i=k; i>0; i--)
    {
        char c = s2[i];
        s2[i] = s2[i-1];
        s2[i-1] = c;
        cost2++;
    }

    a2[s2[0]-'a'] -= 2;
    cost2 += rec(s2.substr(1, s2.size()-2), mp, a2);

    mp[s] = min(cost1, cost2);
    return mp[s];    
}

int main()
{

    while(1)
    {
        string s;
        cin>>s;
        if(s.compare("0")==0) break;
        vector<int> arr(26,0);
        for(char c : s)
            arr[c-'a']++;

        int odd_count=0;
        for(int i: arr)
            if(i%2) odd_count++;

        if(odd_count>1) cout<<"Impossible\n";

        else
        {
            unordered_map<string, int> mp;
            int ans = rec(s,mp,arr);
            cout<<ans<<endl<<endl;
        }
    }
}