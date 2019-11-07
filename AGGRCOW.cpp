#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, c;
        cin>>n;
        cin>>c;

        vector<int> poles(n , -1);
        for(int i=0; i<n; i++)
            cin>>poles[i];

        sort(poles.begin(), poles.end());

        int i = 1;
        int j =poles[n-1] - poles[0];
        int ans;

        while(i<=j)
        {
            int mid = (i+j)/2;

            int f = poles[0], temp=0;
            for(int k=1; k<n; k++)
            {
                if(poles[k] - f >= mid)
                {
                    temp++;
                    f = poles[k];
                }
            }

        
            if(temp >= c-1)
            {
                i = mid+1;
                ans = mid;
            }

            else
                j = mid-1;
        }


        cout<<ans;
    }

    return 0;


}