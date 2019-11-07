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
int b[100009];
ll tot[100009];
vi g[100009];
ll dp[100009][3];
void dfs(int v,int p){
	dp[v][0] = 0;
	dp[v][1] = tot[v];
	dp[v][2] = -1e18;
	trav(i,g[v]) if(i!=p) {
		dfs(i,v);
		dp[v][2] = max({dp[v][2]+dp[i][0],dp[v][2]+dp[i][1]-b[v],dp[v][0]+dp[i][1],dp[v][2]+dp[i][2]});
		dp[v][0] += max(dp[i][0],dp[i][2]);
		dp[v][1] += max({dp[i][0],dp[i][1]-b[i]-b[v],dp[i][2]-b[i]});
	}
}
void solve(){
	int n;cin>>n;
	repA(i,1,n) cin>>b[i],tot[i]=b[i];
	rep(i,n-1){
		int u,v;cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
		tot[u]+=b[v];
		tot[v]+=b[u];
	}
	dfs(1,0);
	cout<<max({dp[1][0],dp[1][1],dp[1][2]});
	repA(i,1,n) g[i].clear();
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) cout<<"Case #"<<i+1<<": ",solve(),cout<<'\n';
	return 0;
}

