/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// int numnodes(TreeNode *root)
// {
//     if(!root) return 0;
//     return(numnodes(root->left) + numnodes(root->right) +1);
// }
int height(TreeNode *root)
{
    if(!root) return 0;
    return max(height(root->right), height(root->left))+1;
}

void fill_t_l(TreeNode *root, unordered_map<TreeNode*, TreeNode *> &T, unordered_map<TreeNode*,int> &L, int level, TreeNode * parent)
{
    if(!root) return;
    T[root] = parent;
    L[root] = level;

    fill_t_l(root->left, T, L, level+1, root);
    fill_t_l(root->right, T, L, level+1, root);
}

void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode *> &P, unordered_map<TreeNode*, TreeNode *> &T, unordered_map<TreeNode*,int> &L, int nr)
{
    if(!root) return;

    if(T[root] == root)
        P[root] = root;
    else if(L[root] < nr)
        P[root] = P[T[root]];

    else if(!(L[root]%nr))
        P[root] = T[root];

    else P[root] = P[T[root]];

    dfs(root->left, P, T, L, nr);
    dfs(root->right, P, T, L, nr);
}



TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{

    int nr = sqrt(height(root));
    cout<<"NR = "<<nr<<endl;
    // int n = numnodes(root);
    // cout<<"N = "<<numnodes<<endl;
    unordered_map<TreeNode*, TreeNode *> T;
    unordered_map<TreeNode*, int > L;

    L[root] = 0;
    T[root] = root;
    fill_t_l(root, T, L,0, root);

    cout<<"T size = "<<T.size()<<endl;
    cout<<"L size = "<<L.size()<<endl;
    
    for(auto it = T.begin(); it != T.end(); it++)
    {
        cout<<it->first->val<<" : "<<it->second->val<<endl;
    }

    cout<<"--------------------------------"<<endl;
    for(auto it = L.begin(); it != L.end(); it++)
    {
        cout<<it->first->val<<" : "<<it->second<<endl;
    }

    unordered_map<TreeNode*, TreeNode * > P;
    
    dfs(root, P, T, L, nr);

    cout<<"--------------------------------"<<endl;
    for(auto it = P.begin(); it != P.end(); it++)
    {
        cout<<it->first->val<<" : "<<it->second->val<<endl;
    }
    TreeNode* x = p;
    TreeNode* y = q;

    while(P[x] !=P[y])
    {
        if(L[x] > L[y])
            x = P[x];
        else
        {
            y = P[y];
        }
        
    }

    while(x !=y)
    {
        if(L[x] > L[y])
            x = T[x];
        else 
            y = T[y];
    }

    return x;
}


int main()
{
    
    struct TreeNode *root = new TreeNode(3); 
    root->left     = new TreeNode(5);
    root->right = new TreeNode(1);  
    root->left->left = new TreeNode(6); 
    root->left->right = new TreeNode(2); 
    root->right->right = new TreeNode(8);
    root->right->left = new TreeNode(0);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *ans = lowestCommonAncestor(root, root->left->left, root->left->right);
    cout<<"Answer = "<<ans->val<<endl;
    return 0;

}