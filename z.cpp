# include <bits/stdc++.h>

using namespace std;

vector<int> calZ(string s)
{
    vector<int> z(s.length(), -1);
    int left =0;
    int right = 0;
    z[0] = 0;
    for(int k=1; k<s.length(); k++)
    {
        if(k>right)
        {
            left =k;
            right = k;
            while(right < s.length() && s[right] == s[right-left])
                right++;

            z[k] = right-left;
            right--;
        }

        else
        {
            int k1 = k-left;
            if(z[k1] < right -k +1)
                z[k] = z[k1];

            else
            {
                left = k;
                while(right < s.length() && s[right] == s[right-left])
                    right++;
                z[k] = right-left;
                right--;

            }
        }
        
    }

    return z;
}



int main()
{
    string s, pat;
    cin>>s>>pat;
    string n = pat + '$' + s;
    vector<int> z = calZ(n);
    cout<<n<<endl;
    for(int i=0; i<z.size(); i++)
        cout<<z[i]<<" | ";
    cout<<endl;


    for(int i=pat.length(); i<z.size(); i++)
    {
        cout<<i<<endl;
        if(z[i] == pat.length())
            cout<<"Found Pattern at : "<<i-(pat.length())<<endl;
        cout<<endl;
    }
    return 0;
}
/*
ok
*/