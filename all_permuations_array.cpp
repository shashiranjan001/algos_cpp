#include<bits/stdc++.h>
using namespace std;

vector<int> A;
void sw(vector<int> &A, int l, int i)
{
    int c = A[l];
    A[l] = A[i];
    A[i] = c;
}
set<vector<int>> permute(int l, int h)
{
    set<vector<int>> rtr;
    if(l==h) 
    {
        rtr.insert({A[l]});
        return rtr;
    }

    for(int i=l; i<=h; i++)
    {
        sw(A,l,i);
        set<vector<int>> res = permute(l+1, h);
        for(auto it:res)
        {
            reverse(it.begin(), it.end());
            it.push_back(A[l]);
            reverse(it.begin(), it.end());
            rtr.insert(it);
        }
        sw(A,l,i);
    }

    return rtr;
}
int main()
{
    int n;
    cin>>n;
    A.assign(n,0);
    for(int i=0; i<n; i++) cin>>A[i];
    set<vector<int>> res = permute(0,n-1);
    for(auto v : res)
    {
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    cout<<"--------------\n";
}