# include<bits/stdc++.h>
using namespace std;

    int sto(string s)
    {
        if(s.length() >1 && s[0] == '0')
            return 450;
        int sum =0;
        int i=s.length()-1;
        while(i >= 0)
        {
            sum += (s[i]-'0')*pow(10, s.length()-1-i);
            i--;
        }
        return sum;
    }
    vector<string> calc(string s, int low, int l, int n)
    {
        vector<string> rtr;
        
        
        if(l>3*n || l<n) return rtr;

        if(n==1)
        {
            if(sto(s.substr(low, l)) <= 255)
            rtr.push_back(s.substr(low, l));
            return rtr;
        }
        
        for(int i=low; i<low+l && i<low+3; i++)
        {
            if(sto(s.substr(low, i-low+1))<=255)
            {
                vector<string> rt = calc(s, i+1, l-((i-low)+1), n-1);
                for(int k=0; k<rt.size(); k++)
                    rtr.push_back(s.substr(low, i-low+1)+'.'+rt[k]);
            }
        }
        
        return rtr;
    }

int main()
{
    string s;
    cin>>s;
    vector<string> ans = calc(s, 0, s.length(), 4);
    
    for(int i=0 ;i<ans.size(); i++)
        cout<<ans[i]<<endl;
}