#include<bits/stdc++.h>

using namespace std;


long long number(string s)
{
    long long l = s.length();
    long long sum = 0;
    while(l)
    {
        sum += (s[l-1] -'0')*pow(10, s.length()-l);
        l--;
    }

    return sum;
}
vector<long long> splitter(string s, char c)
{
    vector<long long> rtr;
    string t("");
    for(long long i=0; i<s.length(); i++)
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

long long compareVersion(string version1, string version2) {
    vector<long long> v1 = splitter(version1, '.');
    vector<long long> v2 = splitter(version2, '.');


    long long sz = min(v1.size(), v2.size());
    long long i=0;
    while(i<sz)
    {
        if(v1[i]<v2[i])
            return -1;
        else if(v1[i]>v2[i])
            return 1;
        i++;
    }
    
    long long f=0;
    while(i<v1.size())
    {
        if(v1[i++])
            f=1;
    }

    while(i<v2.size())
    {
        if(v2[i++])
            f=-1;
    }

    return (int)f;
}