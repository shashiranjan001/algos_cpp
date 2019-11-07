#include <bits/stdc++.h>

using namespace std;

int foo()
{
    static int z = 0;
    return ++z;
}
int main()
{
    cout<<foo()<<endl;
    cout<<foo()<<endl;
    cout<<foo()<<endl;
}