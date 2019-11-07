#include<bits/stdc++.h>
using namespace std;

string kcoma(string s, int k)
{
	int n=s.length();
	int msz = n-k;
	cout<<"s = "<<s<<" n = "<<n<<" msz = "<<msz<<endl;
	string rtr=s.substr(0,msz);
	for(int i=1; i+msz-1<n; i++)
	{
		string tmp = s.substr(i, msz);
		if(rtr.compare(tmp)<0)
			rtr = tmp;
	}

	return rtr;
}

int main()
{
	string s="89769957";
	int k=3;
	cout<<kcoma(s,k)<<endl;
	return 0;
}