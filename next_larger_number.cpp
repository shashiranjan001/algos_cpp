# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
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
    
    int nextGreaterElement(int n) {
        if(!(n/10))
            return -1;
        if(n == INT_MAX)
            return -1;
        string num = to_string(n);
        int f=0;
        for(int i=num.length()-2; i>=0; i--)
        {
            if(num[i]<num[i+1])
            {
                int pos;
                for(int j=num.length()-1; j>=i+1; j--)
                {
                    if(num[j] > num[i])
                    {
                        pos = j;
                        break;
                    }
                }
                int j = pos;
                char temp = num[j];
                num[j] = num[i];
                num[i] = temp;

                string t = num.substr(i+1);
                reverse(t.begin(), t.end());
                num = num.substr(0,i+1) + t;
                f=1;
                break;
            }
            
        }
        
        if(f)
            return number(num);
        return -1;
    }
};