# include <bits/stdc++.h>

using namespace std;

vector<int> lps(string pat)
{
    vector<int> LPS(pat.length(), -1);
    int j=0, i=1;
    LPS[0] = 0;
    while(i<pat.length())
    {
        if(pat[i] == pat[j])
            LPS[i++] = ++j;

        else
        {
            if(j!=0)
                j = LPS[j-1];
            
            else
                LPS[i++] = 0;
        }
    }
    return LPS;
}

int main()
{
    string s;
    string pat;
    cin>>s;
    cin>>pat;

    cout<<"S = "<<s<<endl;
    cout<<"Pat = "<<pat<<endl;
    vector<int> LPS = lps(pat);
    for(int i=0; i<LPS.size(); i++)
        cout<<LPS[i]<<" | ";
    cout<<endl;
    int i=0;
    int j=0;
    while(i < s.length() && j < pat.length())
    {
        if(s[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
                j = LPS[j-1];
            else
                i++;
        }
    }
    if(j == pat.length())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
}

