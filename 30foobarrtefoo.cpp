# include<bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    map<string, int> st;
    int n = words.size();
    int l = words[0].length();
    for(int i=0; i<n; i++)
        st[words[i]]++;
    
    vector<int> rtr;
    int i=0;
    map<string, int> tmp;
    while(i<s.length())
    {
        if(st.find(s.substr(i, l)) != st.end())
        {
            if(tmp.find(s.substr(i, l)) != tmp.end() && tmp[s.substr(i, l)] == st[s.substr(i, l)])
            {
                
                for(auto it = tmp.begin(); it != tmp.end(); it++)
                    it->second = 0;
                
                i = i+1;
                continue;
            }
            tmp[s.substr(i, l)]++;


            int f=1;
            for(auto it = tmp.begin(); it != tmp.end(); it++)
            {
                if(st[it->first] != it->second)
                    f =0;
            }


            if(f)
            {
                rtr.push_back(i-(n-1)*l);
                for(auto it = tmp.begin(); it != tmp.end(); it++)
                    it->second = 0;
            }

            i += l;
        }
        
        else
        {
            for(auto it = tmp.begin(); it != tmp.end(); it++)
                it->second = 0;
            i += 1;
        }
    }
    
    return rtr;
    
}


int main()
{
    int n;
    cin>>n;
    string s;
    vector<string> words(n);
    cin>>s;
    for(int i=0; i<n; i++)
        cin>>words[i];

    cout<<s<<endl;
    for(int i=0; i<n; i++)
        cout<<words[i]<<", ";
    cout<<endl;

    vector<int> res = findSubstring(s, words);

    cout<<"res.size = "<<res.size()<<endl;
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<", ";
    cout<<endl;
}