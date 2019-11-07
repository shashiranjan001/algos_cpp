# include<bits/stdc++.h>
using namespace std;


bool isMatch(string s, string p) {
        
    int i=0, j=0;
    while(j<s.length() && i<p.length())
    {
        // cout<<"BOOM BOOM\n";
        string t("");
        char c;
        int star;
        if(i < p.length()-1)
        {
            // cout<<"I am here\n";
            t += p[i];
            t += p[i+1];
            c = t[0];
            // cout<<"t = "<<t<<endl;
            if(t[1] == '*')
            {
                star = 1;
                i = i+2;
                while(p[i] == c)
                    i++;
            }
            
            else
            {
                star =0;
                i = i+1;
            }
        }
        
        else
        {
            // cout<<"I am in else\n";
            star =0;
            c = p[i++];
            // cout<<"c = "<<c<<" i` = "<<i<<endl;
        }
        // cout<<"Star = "<<star<<endl;
        if(star)
        {
            // cout<<"c = "<<c<<" j` = "<<j<<endl;
            if(c == '.')
            {
                if(i == p.length())
                    return true;
                else
                {
                    while(j<s.length() && j != p[i])
                        j++;
                    if(j==s.length()) return false;
                }
                
            }
                
            else
                while(s[j] == c) j++;
            // cout<<"i` = "<<i<<" j` = "<<j<<endl;
        }
        
        else
        {
            // cout<<"i` = "<<i<<" j` = "<<j<<endl;
            if(s[j] == c || c == '.') j++;
            else return false;
        }
    }
    // cout<<"i = "<<i<<" j = "<<j<<endl;
    if(i>=p.length() && j >= s.length())
        return true;
    return false;
        
    }

bool regex_match(string s, string regex)
{
    if(!regex.length())
        return (s.length() == 0);
    bool first_match = (s[0] == regex[0] || regex[0] == '.');

    if(regex.length() >= 2 && regex[1] == '*')
        return ((regex_match(s, regex.substr(2)))||(first_match && regex_match(s.substr(1), regex)));
    else
    {
        return (first_match && regex_match(s.substr(1), regex.substr(1)));
    }
    
}

bool reg_dp(string s, string p)
{
    vector<vector<bool> > dp(s.length()+1, vector<bool>(p.length()+1));
    dp[s.length()][p.length()] = true;
    for(int i = s.length(); i>=0; i--)
    {
        for(int j = p.length()-1; j>=0; j--)
        {
            bool first_match = (i < s.length() &&(s[i] == p[j] || p[j] == '.'));
            if(j+1 < p.length() && p[j+1] == '*')
            {
                
                dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j]);
            }
            
            else
            {
                dp[i][j] = first_match && dp[i+1][j+1];
            }
        }

        
    }

    return dp[0][0];
}

int main()
{
    string s;
    string pat;
    cin>>s;
    cin>>pat;

    // cout<<"S = "<<s<<endl;
    // cout<<"Pat = "<<pat<<endl;
    // cout<<isMatch(s, pat)<<endl;
    cout<<regex_match(s, pat)<<endl;
    cout<<reg_dp(s, pat)<<endl;
}


class Solution {
public:
    /* you may need to use some attributes here */

    /*
    * @param A: An integer array
    */
    
    vector<long long> segarr;
    int seg_sz;
    int sz;
    void construct_segtree(vector<int> &A, vector<long long> &segarr, int low, int high, int pos)
    {
        if(low == high)
        {
            segarr[pos] = A[low];
            return;
        }
        
        int mid = (low+high)/2;
        
        construct_segtree(A, segarr, low, mid, 2*pos+1);
        construct_segtree(A, segarr, mid+1, high, 2*pos+2);
        
        segarr[pos] = segarr[2*pos+1] + segarr[2*pos+2];
        return;
    }
    Solution(vector<int> A) {
        // do intialization if necessary
        sz = A.size();
        int p = log2(sz);
        seg_sz = 2*sz-1;
        if(pow(2, p) < sz)
            seg_sz = 2*((int)pow(2, p+1)) -1;
            
        vector<long long> t(seg_sz, -1);
        segarr = t;
        
        for(int i=0; i<seg_sz; i++)
            cout<<segarr[i]<<"|";
        cout<<endl<<endl;
        
        construct_segtree(A, segarr, 0, sz-1, 0);
        for(int i=0; i<seg_sz; i++)
            cout<<i<<" : "<<segarr[i]<<endl;
    }

    /*
     * @param start: An integer
     * @param end: An integer
     * @return: The sum from start to end
     */
     
    long long q(vector<long long> &segarr, int low, int high, int pos, int st, int end)
    {
        if(st<= low && end>= high)
            return segarr[pos];
        if(low > end || high < st)
            return 0;
            
        int mid = (low+high)/2;
        // if(end<=mid)
        //     return q(segarr, low, mid, st, end);
        // else if(st > mid)
        //     return q(segarr, mid+1, high, st, end);
            
        return q(segarr, low, mid, 2*pos+1, st, high) + q(segarr, mid+1, high, 2*pos+2, st, end);
    }
     
     
    long long query(int start, int end) {
        // write your code here
        long long out = q(segarr, 0, sz-1, 0, start, end);
        cout<<"sum from "<<start<<" : "<<end<<" = "<<out<<endl;
        return out;
        
    }

    /*
     * @param index: An integer
     * @param value: An integer
     * @return: nothing
     */
    void update(vector<long long> &segarr, int low, int high, int pos, int index, int value)
    {
        if(low == high)
        {
            segarr[pos] = value;
            return;
        }
        
        int mid = (low+high)/2;
        if(index <= mid)
            update(segarr, low, mid, 2*pos+1, index, value);
            
        else
            update(segarr, mid+1, high, 2*pos+2, index, value);
            
        segarr[pos] = segarr[2*pos+1] + segarr[2*pos+2];
        return;
    }
    void modify(int index, int value) {
        // write your code here
        
        update(segarr, 0, sz-1, 0, index, value);
        for(int i=0; i<seg_sz; i++)
            cout<<i<<" : "<<segarr[i]<<endl;
        return;
    }
};








[65,36,115,46,77,64,23,106,113,44,83,78,37,16,7,34,1,76,3,14,77,16,71,50,33,108,115,118,45,40,23,98,57,52,107,94,21,104,47,74,113,44,75,46,53,56,23,10,9,84,99,86,69,40,103,34,113,108,43,54]
17
84
1023