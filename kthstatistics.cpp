#include <bits/stdc++.h>

using namespace std;

int kthpos(vector<int> &v, int l, int h, int k)
{
    if(l==h) return v[l];
    // srand(time(0));
    int ra = rand()%(h-l+1);
    cout<<"ra = "<<ra<<endl;
    int ele = v[l+ra];
    swap(v[l+ra], v[l]);
    int i =l, j = l+1;
    while(j<=h)
    {
        if(v[j]<=ele)
            swap(v[++i], v[j++]);
        else j++;
    }

    
    swap(v[i], v[l]);
    if(i==k) return ele;
    if(i>k)
        return kthpos(v, l, i-1, k);
    return kthpos(v,i+1,h,k);
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> v1;
    for(int i=0; i<n; i++)
        cin>>v[i];

    v1 = v;
    int k;
    cin>>k;
    int ans = kthpos(v,0,n-1,k-1);
    cout<<"ANS = "<<ans<<endl;
    nth_element(v1.begin(), v1.begin()+k-1, v1.end());
    cout<<"ANS 2 = "<<v1[k-1]<<endl;
    for(int x:v1)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}