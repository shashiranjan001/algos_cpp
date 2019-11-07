#include<bits/stdc++.h>

using namespace std;
int prime = 3;

bool test(string s, string pat, int index)
{
    for(int i=0; i<pat.length(); i++)
    {
        if(s[index+i] != pat[i]) return false;
    }
    return true;
}

vector<int> rabinkarp(string s, string pat)
{
    int pl = pat.length();
    int sl = s.length();

    int hash = 0, exp=1;
    for(int i=0; i<pl; i++)
    {
        hash += (pat[i]-'a')*exp;
        exp *= prime;
    }


    int rhash =0, exp2 = 1;
    for(int i=0; i<pl; i++)
    {
        rhash += (s[i]-'a')*exp2;
        exp2 *= prime;
    }
    vector<int> rtr;
    if(rhash == hash && test(s, pat, 0))
        rtr.push_back(0);
    exp /= prime;
    for(int i =1; i+pl<=s.length(); i++)
    {
        rhash = (rhash-(s[i-1]-'a'))/prime + (s[i+pl-1]-'a')*exp;
        if(rhash == hash && test(s, pat, i))
            rtr.push_back(i); 
    }

    return rtr;
}


int main()
{
    string a, b;
    cin>>a>>b;

    vector<int> rtr = rabinkarp(a, b);
    for(int i=0; i<rtr.size(); i++)
        cout<<rtr[i]<<" ";
    cout<<endl;
}