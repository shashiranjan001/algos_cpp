#include<bits/stdc++.h>
using namespace std;


void sw(string &A, int l, int i)
{
    char c = A[l];
    A[l] = A[i];
    A[i] = c;
}
set<string> permute(string &A, int l, int h)
{
    set<string> rtr;
    if(l==h) 
    {
        string t(1, A[l]);
        rtr.insert(t);
        return rtr;
    }

    for(int i=l; i<=h; i++)
    {
        sw(A,l,i);
        set<string> res = permute(A, l+1, h);
        for(auto it:res)
        {
            string t(1, A[l]);
            it = t+it;
            rtr.insert(it);
        }
        sw(A,l,i);
    }

    return rtr;
}
int main()
{
    string A("AABC");
    set<string> res = permute(A, 0,A.length()-1);
    for(auto v : res)
    {
        cout<<v<<endl;
    }
    cout<<"--------------\n";
}