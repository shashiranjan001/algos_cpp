# include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    static bool mysort(pair<int, int> a, pair<int, int> b)
    {
        if(a.first > b.first)
            return true;
        else if(a.first == b.first)
                return true;
        return false;
    }


    string reorganizeString(string S) {
        vector<int> a(26, 0);
        
        for(int i=0; i<S.length(); i++)
        {
            a[S[i] - 'a']++;
        }
        
        vector<pair<int,int> > p_arr;
        for(int i=0; i<26; i++)
            p_arr.push_back(make_pair( a[i], i));
        
        sort(p_arr.begin(), p_arr.end(), mysort);
        if(p_arr[0].first == 1)
            return S;
        int req = p_arr[0].first -1;
        for(int i=1; i<26; i++)
        {
            if(req <= 0)
                req = p_arr[i].first-1;
            else
                req -= p_arr[i].first;
        }
        
        vector<char> arr(S.length(), '`');
        int empty = 0;
        string rtr = "";
        if(req > 0)
        {
            // cout<<"NP";
        }
        
        else
        {
            // cout<<"HP"<<endl;
            int pos = 0;
            for(int i=0; i<26; i++)
            {
                while(p_arr[i].first--)
                {
                    arr[pos] = p_arr[i].second + 'a';
                    pos = (pos+2 >= S.length()) ? 1 : pos+2;
                }
            }
            
            
            
            for(int i=0; i<S.length(); i++)
                rtr += arr[i];
            return rtr;
        }
        
        return rtr;
    }
};

