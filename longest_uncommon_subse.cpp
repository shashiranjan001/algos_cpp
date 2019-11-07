# include<bits/stdc++.h>
using namespace std;
    
bool issub(string pat, string s)
{
    int i=0, j=0;
    while(i<pat.length() && j<s.length())
    {
        if(pat[i] == s[j])
            i++;
        j++;
    }

    return (i == pat.length());

}


int lcs(string X, string Y) 
{ 
    int m = X.length();
    int n = Y.length();
    int L[m + 1][n + 1]; 
    int i, j; 
  
    for (i = 0; i <= m; i++) { 
        for (j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
  
            else if (X[i - 1] == Y[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1; 
  
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    } 
  
    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[m][n]; 
} 

bool mysort(string a, string b)
{
    if(a.length() > b.length())
        return true;
    else
    {
        if(a.length() < b.length())
            return false;
        else return (a.compare(b) < 0);
    }

}

int findLUSlength(vector<string>& strs) {
    if(strs.size() == 1)
        return strs[0].length();
    
    sort(strs.begin(), strs.end(), mysort);
    
    int i=0, j=1;
    while(j<strs.size())
    {
        if(!issub(strs[j], strs[i]))
        {
            if(j==i+1)
                return strs[i].length();
            return strs[j].length();
        }
        
        i=j;
        j=i+1;
    }
    
    return -1;
    
}


int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<issub(s1, s2)<<endl;
}