#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// int main()
// {
//     int n,t;
//     cin>>t;
//     int sz = 1e6;
    
//     vector<char> arr(sz+1, true);
    

    
//     arr[1] = false;
//     for(int i=2; i<=sz; i++)
//     {
//         if(arr[i])
//         {
//             for(ll j=(ll)i*i; j<=sz; j+=i)
//                 arr[j] = false;
//         }
//     }

//     // int n;
//     // vector<char> is_prime(n+1, true);
//     // is_prime[0] = is_prime[1] = false;
//     // for (int i = 2; i * i <= n; i++) {
//     //     if (is_prime[i]) {
//     //         for (int j = i * i; j <= n; j += i)
//     //             is_prime[j] = false;
//     //     }
//     // }
//     cout<<"Hi\n";

//     unordered_set<int> s;
//     for(int i=2; i<=sz; i++)
//         if(arr[i]) s.insert(i);

//     set<int> spp;
    
//     int p1= sqrt(sz);
//     int p2 = pow(sz, (float)(1/(float)4));

//     cout<<"P1 = "<<p1<<" P2 = "<<p2<<endl;

//     for(int i=1; i<=p1; i++)
//     {
//         for(int j=1; j<=p2; j++)
//         {
//             int x = i*i + pow(j,4);
//             if(s.find(x) != s.end()) spp.insert(x);
//         }
//     }
//     vector<int> sp(spp.begin(), spp.end());

//     for(int i=0; i<=10; i++)
//         cout<<sp[i]<<" ";
//     cout<<endl;

//     while(t--)
//     {
//         cin>>n;
//         int id = upper_bound(sp.begin(), sp.end(), n)-sp.begin();
//         cout<<id<<endl;
//     }
//     return 0;
// }


int main()
{
    int n,t;
    cin>>t;
    int sz = 1e6;
    
    vector<int> arr(sz+1, 1);
    
    
    for(int i=2; i<=sz; i++)
    {
        if(arr[i])
        {
            for(ll j=(ll)i*i; j<=sz; j+=i)
                arr[j] = 0;
        }
    }
    
    
    
    int p1= sqrt(sz);
    int p2 = pow(sz, (float)(1/(float)4));
    


    for(int i=1; i<=p1; i++)
    {
        for(int j=1; j<=p2; j++)
        {
            int x = i*i + pow(j,4);
            if(x<=sz && arr[x]==1) arr[x] = 2;
        }
    }
    cout<<"HI\n";

    arr[1] = 0;
    for(int i=2; i<=sz; i++)
    {
        if(arr[i]==2) arr[i] = 1+arr[i-1];
        else arr[i] = arr[i-1];
    }

    for(int i=1; i<=10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    while(t--)
    {
        cin>>n;
        cout<<arr[n]<<endl;
    }
    return 0;
}