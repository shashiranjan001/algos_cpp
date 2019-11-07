#include<bits/stdc++.h>
using namespace std;

long long int helper(long long int h1,long long int h2,vector<long long int> &a,vector<long long int> &b,vector<long long int> &lefta,vector<long long int> &leftb,int n){
	if(n==a.size()){
		if(h1>0||h2>0){
			return 0;
		}
		return 1;
	}
	if(h1>lefta[n] || h2>leftb[n]){
		return 0;
	}
	if(h1<=0 and h2<=0){
		return pow(3,(int)a.size()-n);
	}
	long long int maxi = 0;
	if(h2!=leftb[n])
	maxi+=helper(h1-a[n],h2,a,b,lefta,leftb,n+1);

	maxi+=helper(h1-a[n],h2-b[n],a,b,lefta,leftb,n+1);
	if(h1!=lefta[n])
	maxi+=helper(h1,h2-b[n],a,b,lefta,leftb,n+1);
	return maxi;
}

int main(){
    int t,count=0;
    cin>>t;
    while(t--){
        count++;
        long long int n,h;
        cin>>n>>h;
        vector<long long int> a(n);
        vector<long long int> lefta(n+1);
        vector<long long int> b(n);
        vector<long long int> leftb(n+1);
        lefta[n]=0;
        leftb[n]=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        long long int sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=a[i];
            lefta[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=b[i];
            leftb[i]=sum;
        }
        cout<<"Case #"<<count<<": "<<helper(h,h,a,b,lefta,leftb,0)<<endl;
    }
    return 0;
}