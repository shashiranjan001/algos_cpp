#include<bits/stdc++.h>

using namespace std;


string dfs(int i, vector<set<int>> graph)
{
    string s("(");
    string s2(1, (char)(i+'A'));
    s += s2;

    for(auto it = graph[i].begin(); it != graph[i].end(); it++)
    {
        s+= dfs(*it, graph);
    }

    s +=")";
    return s;
}

int main()
{
    int e;
    cin>>e;
    char c1, c2;
    vector<int> s1(26,0), s2(26,0);
    set<int> t;
    vector<set<int>> graph(26, t);
    for(int i=0; i<e; i++)
    {
        cin>>c1>>c2;
        s1[c1-'A']=1;
        s2[c2-'A'] = 1;
        graph[c1-'A'].insert(c2-'A');
    }

    int root;
    for(int i=0;i<26; i++)
    {
        if(s1[i] && !s2[i]) 
            root =i;
    }
    
    string rtr = dfs(root, graph);
    cout<<"rtr = "<<rtr<<endl;
}