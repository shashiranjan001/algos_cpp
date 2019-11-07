#include<bits/stdc++.h>

using namespace std;
bool isop(char c)
{
    return(c == '+' || c== '-' || c == '-' || c == '/' || c == '*' || c == ')' || c == '(');
}

int comp(string a, char c)
{
    if(c=='(') return 1;
    if(a[0] == '*')
    {
        if(c == '+' || '-') return -1;
        else return 1;
    }

    else if(a[0] == '/')
    {
        if(c == '+' || '-') return -1;
        else return 1;
    }

    return 1;
}
int main()
{
    string s;
    cin>>s;
    cout<<"S = "<<s<<endl;
    stack<string> sym, op;
    sym.push(string(1,s[0]));
    for(int i=1; i<s.size(); i++)
    {
        if(s[i] == ')')
        {
            while(op.top().compare("(") != 0)
            {
                string a=sym.top();
                sym.pop();
                string b = sym.top();
                sym.pop();
                sym.push(b+a+op.top());
                op.pop();
            }
            op.pop();
        }
        else if(isop(s[i]))
        {
            if(!op.empty())
            {
                if(op.top().compare("(") == 0)
                    op.push(string(1,s[i]));
                else if(comp(op.top(), s[i]) < 0)
                {
                    string a = sym.top();
                    sym.pop();
                    string b = sym.top();
                    sym.pop();
                    sym.push(b+a+op.top());
                    op.pop();
                    op.push(string(1,s[i]));
                }
                else
                {
                    op.push(string(1,s[i]));
                }
                
            }

            else op.push(string(1,s[i]));
        }

        else
        {
            sym.push(string(1,s[i]));
        }
    }

    // cout<<"SYMsize = "<<sym.size()<<" opsize = "<<op.size()<<endl;
    // cout<<"SYMTOP = "<<sym.top()<<" OP top = "<<op.top()<<endl;
    // while(sym.size()) cout<<sym.top()<<endl, sym.pop(); 
    // while(op.size()) cout<<op.top()<<endl, op.pop();
    while(op.size())
    {
        string a = sym.top();
        sym.pop();
        string b = sym.top();
        sym.pop();
        sym.push(b+a+op.top());
        op.pop();
    }

    cout<<"RES = "<<sym.top()<<endl;
}