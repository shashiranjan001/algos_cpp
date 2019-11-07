#include<bits/stdc++.h>

using namespace std;

long long main()
{
    vector<long long> a{1,2,3,4};
    vector<long long> b{5,6,7,8};
    vector<long long> c{12,13,14,15};

    swap(a,b);
    swap(b,c);

    for(long long x: a) cout<<x<<" ";
    cout<<"\n------------------\n";

    for(long long x: b) cout<<x<<" ";
    cout<<"\n------------------\n";

    for(long long x: c) cout<<x<<" ";
    cout<<"\n------------------\n";




class Solution {
public:
    long long maxendsum(vector<long long> arr)
    {
        long long gmax=0, sum=0;
        for(long long i=0; i<arr.size(); i++)
        {
            sum += arr[i];
            gmax = max(gmax, sum);
        }
        return gmax;
    }
    long long maxsumsubarray(vector<long long> &arr)
    {
        long long sum=0, gmax=0;
        for(long long x:arr)
        {
            sum+= x;
            gmax = max(sum, gmax);
            if(sum<0) sum=0;
        }
        return gmax;
    }
    long long kConcatenationMaxSum(vector<long long>& arr, long long k) {
        
        // vector<long long> v{-2, -3, 4, -1, -2, 1, 5, -3};
        // cout<<maxsumsubarray(v)<<endl;
        vector<long long> neww;
        long long arrsum = 0;
        for(long long x:arr)
        {
            arrsum += x;
            neww.push_back(x);
        }
        
        for(long long x:arr)
            neww.push_back(x);
        // for(long long x:neww) cout<<x<<" ";
        // cout<<endl;
        long long max_sum= maxsumsubarray(neww);
        // cout<<max_sum<<endl;
        long long end1 = maxendsum(arr);
        reverse(arr.begin(), arr.end());
        long long end2 = maxendsum(arr);
        if(arrsum<0)
        {
            return max_sum;
        }
        
        else
        {
            return max(max_sum, arrsum*(k-2) + end1+end2);
        }
        return 0;
    }
};
}