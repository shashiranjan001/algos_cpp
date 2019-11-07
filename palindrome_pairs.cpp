# include<bits/stdc++.h>
using namespace std;
long long int p = 10e8 + 7; 

long long int d = 31;

int has(string s, int f)
{
    if(f)
        reverse(s.begin(), s.end());
    if(s.length() == 0)
        return -1;
    long long int hash = 0;
    for(char c:s)
    {
        hash = (hash*d + c - 'a')%p;
    }

    return hash;
}

bool ispalindrome(string s, int i)
{
    if(i==s.length()-1)
        return true;
    int len = s.length()-1;
    while(i<len)
    {
        if(s[i] != s[len])
            return false;
    }

    return true;
}


int main()
{
    int n;
    cin>>n;
    vector<string> s(n, "");
    for(int i=0; i<n; i++)
        cin>>s[i];

    unordered_map<int, int> mp1, mp2;

    for(int i=0; i<n; i++)
    {
        mp1[has(s[i],1)] = i;
        mp2[has(s[i],0)] = i;
    }

    vector<vector<int> > ans;
    for(int i = 0; i < n; i++)
    {
        long long int h = 0; 
        if(s[i] == "") 
        {
            for(int j = 0; j < n; j++)
            {
                if(j!=i && ispalindrome(s[j], 0)) { 
                        ans.push_back({i, j});
                        ans.push_back({j, i});
                }
            }
            continue;
        }
        
        // - O(K) - hashing through length of word
        for(int j = 0; j <s[i].length() ; j++)
        {  
            h = (h*d + (s[i][j]-'a') + 1)%p;
                
            // O(K) - checking if remaining word is palindrome -> can be optimized to O(1) by precomputing hashes
            if(mp2.count(h) && mp2[h]!=i && ispalindrome(s[i], j+1))
            {
                if(j == s[i].length()-1 && mp2[h] < i)continue;
                ans.push_back({i, mp2[h]});
            }
        }
        
        // Repeat the same from the other end
        h = 0; 
        for(int j = s[i].length()-1; j >=0 ; j--)
        {
            h = (h*d + s[i][j]-'a' + 1)%p;
            if(mp1.count(h) && mp1[h]!=i  && ispalindrome(s[i], 0))
            {
                if(j == 0 && mp1[h] < i)continue;
                ans.push_back({mp1[h], i});
            }
        }
    }

    cout<<"Size = "<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i][0]<<", "<<ans[i][1]<<endl;
    
    return 0; 
}