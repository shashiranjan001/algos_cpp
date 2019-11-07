# include<bits/stdc++.h>
using namespace std;


int number(string s)
{
    int l = s.length();
    int sum = 0;
    while(l)
    {
        sum += (s[l-1] -'0')*pow(10, s.length()-l);
        l--;
    }

    return sum;
}
vector<int> splitter(string s, char c)
{
    vector<int> rtr;
    string t("");
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == c)
        {
            rtr.push_back(number(t));
            t = t.substr(0,0);
        }
        else
            t += s[i];
    }

    if(t.length())
        rtr.push_back(number(t));

    return rtr;
}


int main()
{
    string version1;
    string version2;
    cin>>version1;
    cin>>version2;
    vector<int> v1 = splitter(version1, '.');
    vector<int> v2 = splitter(version2, '.');

    for(int i=0 ;i<v1.size(); i++)
        cout<<v1[i]<<" | ";
    cout<<endl;

    for(int i=0 ;i<v2.size(); i++)
        cout<<v2[i]<<" | ";
    cout<<endl;

    int sz = min(v1.size(), v2.size());
    int i=0;
    while(i<sz)
    {
        if(v1[i]<v2[i])
            return -1;
        else if(v1[i]>v2[i])
            return 1;
        i++;
    }

    int f=0;
    while(i<v1.size())
    {
        if(v1[i])
            f=1;
    }

    while(i<v2.size())
    {
        if(v2[i])
            f=-1;
    }

    return f;
    

    return 0;
}