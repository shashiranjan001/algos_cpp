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

void solve(){
	int n,s;cin>>n>>s;
	vector<vi> z;
	map<vi,int> m;
	rep(i,n){
		int x;cin>>x;
		vi v(x);
		rep(j,x) cin>>v[j];
		sort(all(v));
		m[v]++;
		z.pb(v);
	}
	ll ans = 0;
	trav(j,z){
		ans+=n;
		rep(i,(1<<sz(j))){				5 80 90 100
			vi cur;
			rep(k,sz(j)){
				if((1<<k)&i) cur.pb(j[k]);
			}
			ans-=m[cur];
		}
	}
	cout<<ans;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) cout<<"Case #"<<i+1<<": ",solve(),cout<<'\n';
	return 0;
}

