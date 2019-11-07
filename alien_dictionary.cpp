#include <bits/stdc++.h>

using namespace std;

int flag =0;
vector<char> resolver(string a, string b)
{
    int i=0;
    while(i<a.size() && i<b.size())
    {
        if(a[i] != b[i])
            return {a[i], b[i]};
        i++;
    }
    return {'#', '#'};
}
    

void dfs(char c, vector<vector<int>> &graph, vector<char> &visited, stack<char> &stk)
{
    for(int i=1; i<=26; i++)
    {
        if(visited[i-1] == 0)
        {
            visited[i-1] = 1;
            dfs('a'+i-1, graph, visited, stk);
            if(flag) return;
        }
        
        else if(visited[i-1]==1)
        {
            flag=1;
            return;
        }
    }
    visited[c-'a'] = 2;
    stk.push(c);
}
    
string alienOrder(vector<string> &words) {
    // Write your code here
    
    
    vector<int> v(27, -1);
    vector<vector<int>> graph(26, v);
    
    
    for(int i=1; i<words.size(); i++)
    {
        vector<char> p = resolver(words[i], words[i-1]);
        if(p[0] == '#') continue;
        graph[p[0]-'a'][p[1]-'a'+1] = 1;
        graph[p[0]-'a'][0] = 1;
    }
    
    for(int i=0; i<26; i++)
    {
        if(graph[i][0] != -1)
        {
            cout<<(char)('a'+i)<<" : ";
            for(int j=1; j<27; j++)
            {
                if(graph[i][j] == 1)
                    cout<<(char)('a'+j-1)<<" ";
            }
            cout<<endl;
        }
    }
    
    vector<char> visited(26,1);
    for(int i=0; i<26; i++)
    {
        if(graph[i][0] != -1)
            visited[i] = 0;
    }
    
    stack<char> stk;
    for(int i=0; i<26; i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;
            dfs('a'+i, graph, visited, stk);
            if(flag) break;
        }
    }
    
    string rtr("");
    if(flag) return rtr;
    while(stk.size())
    {
        rtr = stk.top() + rtr;
        stk.pop();
    }
    
    return rtr;
}

int main()
{
    vector<string> v{};
    
}
//aao
////thik h

