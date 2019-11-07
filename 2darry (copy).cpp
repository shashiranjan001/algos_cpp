#include <bits/stdc++.h>
using namespace std;
void rec(int dp[2][2][3])
{
	dp[0][0][0] = 1;
	dp[1][1][2] = 9;
}
int main() {
	int dp[2][2][3];
    memset(dp, -1, sizeof dp);
	
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
		{
			for(int k=0; k<3; k++)
				cout<<dp[i][j][k]<<" ";
			cout<<endl;
		}
	}
	
	cout<<"----------------\n";
	// memst(dp, -1, sizeof(dp));
	rec(dp);
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
		{
			for(int k=0; k<3; k++)
				cout<<dp[i][j][k]<<" ";
			cout<<endl;
		}
	}
	return 0;
}