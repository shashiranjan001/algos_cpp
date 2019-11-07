#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    int apple, orange;
    if(s[0] == 'A')
    {
        apple =0;
        orange = 1;
    }
    else
    {
        apple = 1;
        orange = 0;
    }

    for(int i=1; i<n; i++)
    {
        if(s[i] == 'A')
            orange = 1+min(orange, apple);
        else
        {
            orange = min(apple, orange);
            apple = 1+apple;
        }
    }
    cout<<"ANSWER = "<<min(apple, orange)<<endl;
    return 0;
}