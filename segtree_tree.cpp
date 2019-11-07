#include<bits/stdc++.h>
using namespace std;
struct segnode{
    int val;
    segnode *l, *r;
    segnode(){l = NULL; r = NULL;}
};

void update(segnode *root, int low, int high, int rlow, int rhigh, int delta)
{
    if(low > high || rlow>high || rhigh < low) return;
    
    if(low == high)
    {
        root->val += delta;
        return;
    }
    
    int mid = (low + high)/2;
    update(root->l, low, mid, rlow, rhigh, delta);
    update(root->r, mid+1, high, rlow, rhigh, delta);
    root->val = root->l->val + root->r->val;
}

int query(segnode *root, int low, int high, int qlow, int qhigh)
{
    if(qlow>high || qhigh < low) return 0;
    if(qlow <= low && qhigh >= high)
        return root->val;

    int mid = (low+high)/2;
    return (query(root->l, low, mid, qlow, qhigh) + query(root->r, mid+1, high, qlow, qhigh));
}

segnode* buildtree(vector<int> &v, int low, int high)
{
    segnode *root = new segnode();
    if(low > high) return NULL;
    if(low == high)
    {
        root->val = v[low];
        return root;
    }

    int mid = (low+high)/2;
    root->l = buildtree(v, low, mid);
    root->r = buildtree(v, mid+1, high);

    root->val = root->l->val + root->r->val;
}

void printtree(segnode *root)
{
    if(!root) return;
    printtree(root->l);
    cout<<root->val<<" | ";
    printtree(root->r);
}
int main()
{
    vector<int> v{2,0,9,4,6,1,10,7,5,3};
    segnode *root  = buildtree(v, 0, v.size()-1);
    cout<<"BUILD DONE"<<endl;
    printtree(root);
    cout<<endl;
    cout<<"Answer = "<<query(root, 0, 9, 4, 8)<<endl;
    update(root, 0, v.size()-1, 4, 7, 4);
    cout<<"UPDATE DONE"<<endl;
    printtree(root);
    cout<<endl;
    return 0;
}