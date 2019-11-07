#include<bits/stdc++.h>

using namespace std;

vector<int> solve(string s)
{
    vector<int> rtr(26,0);
    int n = s.length()-1;
    for(int i=n; i>=0;)
    {
        if(s[i]==')')
        {
            i--;
            int num=0, c=1;
            while(s[i] != '(')
            {
                num+= c*(s[i]-'0');
                c*=10;
                i--;
            }
            i--;
            int num2=0;
            if(s[i]=='#')
            {
                num2 += (s[i-1]-'0')+10*(s[i-2]-'0');
                i=i-3;
            }

            else
            {
                num2 = (s[i]-'0');
                i=i-1;
            }
            rtr[num2-1] += num;
        }

        else
        {
            int num2=0;
            if(s[i]=='#')
            {
                num2 += (s[i-1]-'0')+10*(s[i-2]-'0');
                i=i-3;
            }

            else
            {
                num2 = (s[i]-'0');
                i=i-1;
            }
            rtr[num2-1]++;
        }
    }

    return rtr;
}

int main()
{
    string s;
    cin>>s;
    vector<int> arr = solve(s);
    for(int i=0; i<26; i++)
    {
        if(arr[i])
        {
            cout<<(char)(i+'a')<<" : "<<arr[i]<<endl;
        }
    }
}