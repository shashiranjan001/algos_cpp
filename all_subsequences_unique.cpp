#include<bits/stdc++.h>

using namespace std;
unordered_set<string> st;
string m;
int n;
void rec(int pos, string s)
{
    if(st.find(s) == st.end() && s.size())  st.insert(s);
    if(pos == n) return;
    string temp(1, m[pos]);
    rec(pos+1, s);
    rec(pos+1, s+temp);
}


int main()
{
    cin>>m;
    n = m.length();
    rec(0,"");
    cout<<"SUBSEQUENCES : ";
    for(string s:st)
        cout<<s<<" ";
    cout<<endl;
}