# include<bits/stdc++.h>

using namespace std;


bool ispossible(int guess, int k, vector<int> v)
{
    if(guess < *max_element(v.begin(), v.end())) return false;
    int n = v.size();
    int sum=0, cnt=0;
    for(int i=0; i<n; )
    {
        if(sum + v[i] > guess)
        {
            cnt++;
            sum=0;
        }

        else
        {
            sum += v[i];
            i++;
        }
    }

    if(cnt<=k) return true;
    return false;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n,0);
    for(int i=0; i<n; i++)
        cin>>v[i];

    int s=0;
    for(int x : v) s+= x;

    for(int x : v) cout<<x<<endl;


    int h = s;
    int l = *min_element(v.begin(), v.end());

    int ans = INT_MAX;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(ispossible(mid, k, v))
        {
            ans = min(ans, mid);
            h = mid-1;
        }

        else
            l = mid+1;
    }

    cout<<"Answer = "<<ans<<endl;
    return 0;
}