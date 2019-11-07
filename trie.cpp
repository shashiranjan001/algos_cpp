#include<bits/stdc++.h>


using namespace std;
struct Trie{

    vector<int> words; // index of words
    vector<Trie *> children;
    Trie() {
        children = vector<Trie *>(26, nullptr);
    }
};


void add(Trie *a, string w, int id, int index)
{
    if(index == w.size()) return;
    if(!a->children[w[index]-'a'])  a->children[w[index]-'a'] = new Trie();
    a = a->children[w[index]-'a'];
    a->words.push_back(id);
    
    add(a, w, id, index+1);
}


vector<int> find(Trie *a, string prefix, int index)
{
    vector<int> rtr;
    if(!a) return rtr;
    if(index == prefix.length()) return a->words;
    return find(a->children[prefix[index]-'a'], prefix, index+1);
}

int main()
{
    int n;
    cin>>n;
    vector<string> v(n, "");
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    Trie *p = new Trie();
    Trie *s = new Trie();
    for(int i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    for(int i=0; i<n; i++)
        add(p, v[i], i, 0);

    for(int i=0; i<n; i++)
    {
        reverse(v[i].begin(), v[i].end());
        add(s, v[i], i, 0);
    }

    string prefix("a");
    string suffix("e");
    vector<int> parr = find(p, prefix, 0);
    vector<int> sarr = find(s, suffix, 0);

    for(int x :parr) cout<<x<<endl;

    vector<int> common;
    unordered_set<int> st;
    for(int x :parr) st.insert(x);

    int max_id =-1;
    for(int i=0; i<sarr.size(); i++)
    {
        if(st.find(sarr[i]) != st.end() && max_id<i) max_id = i;
            
    }

    cout<<"Answer = "<<max_id<<endl;
    return 0;


}

// 4
// apple
// ape
// banana
// baana



