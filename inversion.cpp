#include<bits/stdc++.h>

using namespace std;

int cost=0;
void merge(vector<int> &v, int l, int mid, int h)
{
    vector<int> t;
    int i=l, j=mid+1;
    while(i<=mid && j<=h)
    {
        if(v[i]>v[j])
        {
            cost += mid-i+1;
            t.push_back(v[j]);
            j++;
        }
        else
        {
            t.push_back(v[i]);
            i++;
        }
    }

    while(i<=mid)
    {
        t.push_back(v[i]);
        i++;
    }

    while(j<=h)
    {
        t.push_back(v[j]);
        j++;
    }

    int k =l;
    for(int i=0; i<t.size(); i++)
        v[k++] = t[i];
}
void mergesort(vector<int> &v, int l ,int h)
{
    if(l>=h) return;
    int mid = l + (h-l)/2;
    mergesort(v, l, mid);
    mergesort(v, mid+1, h);

    merge(v, l, mid, h);
}
int inversions(vector<int> &v)
{
    int l=0, h=v.size()-1;
    mergesort(v, l, h);
}

int main()
{
    vector<int> v{2,4,1,3,5};

    inversions(v);
    cout<<cost<<endl;
    return 0;
}