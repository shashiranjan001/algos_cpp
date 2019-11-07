#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 


using namespace __gnu_pbds; 
using namespace std;
#define int  long long

typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    new_data_set; 

int lb(vector<pair<int,int>> &v, int l, int h, int key)
{
    if(l==h)
    {
        if(v[l].first<key) return h+1;
        return l;
    }
    int mid = l + (h-l)/2;
    if(v[mid].first>=key)
        return lb(v, l, mid,key);
    return lb(v, mid+1, h,key);
}



signed main()
{
    int t;
    cin>>t;
    for(int z=1; z<=t; z++)
    {
        int n, h;
        cin>>n>>h;

        vector<int> a(n), b(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
            cin>>b[i];

        int mid = n/2;
        int maxx1 = pow(3,mid);
        int maxx2 = pow(3, n-mid);
        vector<pair<int,int>> seta(maxx1), setb(pow(3,n-mid));
        vector<int> factor(mid+1);
        factor[0] = 1;
        for(int i=1; i<=mid; i++)
            factor[i] = factor[i-1]*3;

        
        for(int i=0; i<maxx1; i++)
        {
            int s1=0, s2=0;
            for(int j=0; j<mid; j++)
            {
                int val = i/factor[j];
                if(val%3 == 0)
                {
                    s1 += a[j];
                    s2 += b[j];
                }

                else if(val%3 == 1)
                    s1 += a[j];
                else s2 += b[j];
            }

            seta[i] = {s1,s2};
        }

        for(int i=0; i<maxx2; i++)
        {
            int s1=0, s2=0;
            for(int j=0; j<n-mid; j++)
            {
                int val = i/factor[j];
                if(val%3 == 0)
                {
                    s1 += a[j+mid];
                    s2 += b[j+mid];
                }

                else if(val%3 == 1)
                    s1 += a[j+mid];
                else s2 += b[j+mid];
            }

            setb[i] = {s1,s2};
        }

        sort(setb.begin(), setb.end());
        // cout<<"maxx1 = "<<maxx1<<endl;
        // cout<<"maxx2 = "<<maxx2<<endl;
        // cout<<"SETA"<<endl;
        // for(auto p : seta)
        //     cout<<p.first<<" "<<p.second<<endl;


        // cout<<"SETB"<<endl;
        // for(auto p : setb)
        //     cout<<p.first<<" "<<p.second<<endl;


        int ways = 0;
        // cout<<"h = "<<h<<" n = "<<n<<endl<<endl;
        for(int i=0; i<maxx1; i++)
        {
            // cout<<"seata["<<i<<"].first = "<<seta[i].first<<":"<<h-seta[i].first<<endl;
            int l = lb(setb,0,setb.size()-1, h-seta[i].first);
            // cout<<"i = "<<i<<" : l = "<<l<<endl;
            if(l!=setb.size())
            {
                new_data_set mp;
                for(int j=l; j<setb.size(); j++)
                    mp.insert(setb[j].second);
                
                int it = mp.order_of_key(h-seta[i].second);
                // cout<<"it = "<<it<<endl;
                ways += mp.size()-it;
                // cout<<endl<<endl;
            }
        }

        cout<<"Case #"<<z<<": "<<ways<<endl;
    } 

    return 0;
}