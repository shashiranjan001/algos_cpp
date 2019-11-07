#include<bits/stdc++.h>
using namespace std;
struct segnode{
    int val;
    segnode *l, *r;
    segnode(){l = NULL; r = NULL;}
};

void update(segnode *root, unsigned long long low, unsigned long long high, int pos, int value)
{
    if(low > high) return;
    
    if(low == high)
    {
        root->val = value;
        return;
    }

    unsigned long long mid = low + (high - low)/2;
    if(pos<=mid)
    {
        if(!root->l)
        {
            segnode *l = new segnode();
            root->l = l;
        }
        update(root->l, low, mid, pos, value);
    }

    else
    {
        if(!root->r)
        {
            segnode *r = new segnode();
            root->r = r;
        }
        update(root->r, mid+1, high, pos, value);
    }
    
    if(root->l && root->r)
        root->val = root->l->val + root->r->val;

    else if(root->l && !root->r)
        root->val = root->l->val;

    else
        root->val = root->r->val;
}

int query(segnode *root, unsigned long long low, unsigned long long high, int id)
{
    if(!root) return 0;
    if(id >= high) return root->val;

    unsigned long long mid = low + (high - low)/2;

    int res = query(root->l, low, mid, id);

    if(id>mid) res +=query(root->r, mid+1, high, id);
    return res;
}




void printtree(segnode *root)
{
    if(!root) return;
    cout<<root->val<<" | ";
    printtree(root->l);
    printtree(root->r);
}
int main()
{
    unsigned long long low = 0;
    unsigned long long high = 1e5;
    segnode *root  = new segnode();
    update(root, low, high, 5, 10);
    printtree(root);
    cout<<endl;
    update(root, low, high, 11, 1);
    printtree(root);
    cout<<endl;
    update(root, low, high, 7, -8);
    printtree(root);
    cout<<endl;   
    cout<<"BUILD DONE"<<endl;
    cout<<endl;
    cout<<query(root, 0, 1e5, 8);
    cout<<endl;
    // cout<<"Answer = "<<query(root, 0, 9, 4, 8)<<endl;
    // update(root, 0, v.size()-1, 4, 7, 4);
    // cout<<"UPDATE DONE"<<endl;
    // printtree(root);
    // cout<<endl;
    return 0;
}