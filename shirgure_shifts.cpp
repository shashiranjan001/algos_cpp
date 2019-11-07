#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
using ll = long long; using ld = long double; const char nl = '\n';
/* -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- */

#include <bits/extc++.h>
namespace pbds =  __gnu_pbds;
template <typename key, typename val=pbds::null_type, typename comp=less<key>>
using ostree=pbds::tree<key,val,comp,pbds::rb_tree_tag,pbds::tree_order_statistics_node_update>;
using vi = vector< int >; using vll = vector< ll >;
#define all(x) std::begin(x), std::end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename...Args, template<typename...> typename T> string to_string(T<Args...> const&);
string to_string(string const&s){return '"'+s+'"';}
string to_string(char const &c) {return to_string(string(1,c));}
string to_string(char const *c) {return to_string(string(c));}
string to_string(bool const &b) {return (b ? "T" : "F");}
template<typename... Args> string to_string(pair<Args...> const&p)
{return "("+to_string(p.first)+", "+to_string(p.second)+")";}
template <typename...Args, template<typename...> typename T> string to_string(T<Args...> const&S)
{string s = "{"; for(auto const& e: S)s+=" "+to_string(e);s+=" }"; return s;}
template<typename Tail> void debug_out(Tail t) {cerr<<" "<<to_string(t)<<" ]"<<endl;}
template<typename Head, typename... Tail> void debug_out(Head h, Tail... t)
{cerr << " " << to_string(h) << ","; debug_out(t...);}
#define pr(...) cerr<<"["<<(#__VA_ARGS__)<<"] : [", debug_out(__VA_ARGS__)
template <typename T> void dbr(T lb, T ub)
{cerr<<'{';for(auto it=lb; it!=ub; it++)cerr<<' '<<to_string(*it); cerr<<" }"<<endl;}
template<typename T, typename Comp=less<T>> bool smin(T &mem, T const&v, Comp const&cmp=Comp())
{return cmp(v, mem) ? mem = v, true : false;}
template<typename T, typename Comp=less<T>> bool smax(T &mem, T const&v, Comp const&cmp=Comp())
{return cmp(mem, v) ? mem = v, true : false;}
/* -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- */

ll brute(int n, int h, int a[], int b[]) {
  int t[n+1];
  fill(t, t+n+1, 0);
  ll ans = 0;
  while( t[n] == 0 ) {

    int x = 0, y = 0;
    for(int i=0; i<n; i++) {
      if( t[i] == 0 or t[i] == 2 ) x += a[i];
      if( t[i] == 1 or t[i] == 2 ) y += b[i];
    }

    if( x >= h and y >= h ) {
      ans++;
    }

    for(int i=0; i<=n; i++) {
      t[i]++;
      if( t[i] < 3 ) break;
      t[i] = 0;
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int cases;
  cin >> cases;

  for(int test=1; test<=cases; test++) {
    int n;
    ll h;

    cin >> n >> h;

    int a[n], b[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    int all = (1<<n) - 1;

    ll bad = 0;

    ll unhappy[1<<n];
    fill(unhappy, unhappy + (1<<n), 0);

    for(int mask=0; mask<=all; mask++) {
      ll p = 0;
      for(int j=0, z=1; j<n; j++, z<<=1)
	if( mask & z ) p += b[j];
      if( p < h ) {
	unhappy[mask] = 1;
	bad += (1ll << __builtin_popcount(mask));
      }
    }

    for(int j=0, z=1; j<n; j++, z<<=1)
      for(int mask=0; mask<=all; mask++) {
	if( mask & z ); else unhappy[mask] += unhappy[mask^z];
      }

    for(int mask=0; mask<=all; mask++) {
      ll p = 0;
      for(int j=0, z=1; j<n; j++, z<<=1)
	if( mask & z ) p += a[j];

      if( p < h ) {
	bad += (1ll << __builtin_popcount(mask));
	bad -= unhappy[all^mask];
      }

    }

    ll full = 1; for(int i=0; i<n; i++) full *= 3;

    // pr(n, full, bad);

    ll ans = full - bad ;

#ifdef LIGMA2

    if( n <= 12 ) {
      ll sol = brute(n, h, a, b);
      pr(ans, sol);
      assert( ans == sol );
    }

#endif

    cout << "Case #" << test << ": " << ans << nl;

  }

}
