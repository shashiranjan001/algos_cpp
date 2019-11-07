#include<bits/stdc++.h>


using namespace std;

int main()
{
    int t, tt=1;
    cin>>t;
    while(tt<=t)
    {
        int n, s;
        cin>>n>>s;
        vector<vector<int>> mat;
        for(int i=0; i<n; i++)
        {
            int sz;
            cin>>sz;
            vector<int> temp(sz);
            while(sz--)
                cin>>temp[sz];
            mat.push_back(temp);
        }
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<mat[i].size(); j++)
        //         cout<<mat[i][j]<<" ";
        //     cout<<endl;
        // }
        
        // cout<<"---------------\n";
        
        int sum =0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int flag1=0, found;
                for(int k:mat[i])
                {
                    found=0;
                    for(int l:mat[j])
                    {
                        if(l==k) {found=1;break;}
                    }

                    if(found == 0) {flag1 = 1; break;}
                }
                
                int flag2=0;
                for(int k:mat[j])
                {
                    found=0;
                    for(int l:mat[i])
                    {
                        if(l==k) {found=1;break;}
                    }

                    if(found == 0) {flag2 = 1; break;}
                }
                
                
                sum += flag1 + flag2;
            }
        }
        
        cout<<"Case #"<<tt<<": "<<sum<<endl;
        tt++;
    }
}