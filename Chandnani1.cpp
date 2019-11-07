#include <bits/stdc++.h>
using namespace std;




#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}
int dp[109][109];
int a[109];
int cnt[1009];
void solve(){
	int n,k;cin>>n>>k;k++;
	rep(i,n) cin>>a[i+1];
	fill(dp);
	repA(i,1,n){
		int cur = 0;
		fill(cnt);
		repA(j,0,k) dp[i][j] = 109;
		repD(j,i,1){
			cnt[a[j]]++;
			cur = max(cur,cnt[a[j]]);
			repA(l,1,k) dp[i][l] = min(dp[i][l],dp[j-1][l-1]+i-j+1-cur);
		}
	}
	cout<<dp[n][k];

	
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) cout<<"Case #"<<i+1<<": ",solve(),cout<<'\n';
	return 0;
}

