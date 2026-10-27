#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../../../cpp/debug.cpp"
#else
#define dbg(...)
#endif

long long inf = 1e18;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<pair<ll,ll>>> vvp;
typedef vector<vector<long long>> vvll;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef queue<int> qi;
typedef queue<pii> qpii;

#define sz(x) ll(x.size())
#define fore(i,a,b) for(ll i = a; i<b; i++)
#define forr(x,v) for(auto& x : v)
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define cinv(vec,n) for(int i = 0; i<n; i++) cin>>vec[i];
#define coutv(vec,n) for(int i = 0; i<n; i++) cout<<vec[i]<<" ";
#define cin2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j]<<" "; j++);


#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define F first
#define S second
#define pb push_back

#define fixed(n) fixed << setprecision(n)

void solve(){
	int n,k,p,m; cin>>n>>k>>p>>m; p--;
	vi deck(n); cinv(deck,n);

	auto f = [&](int x) {
		int v =  deck[x];
		deck.erase(deck.begin()+x);
		deck.pb(v);
	};
	int ans = 0;

	while(true) {
		if (p < k) {
			m -= deck[p];
			if (m < 0) break;
			ans++;
			f(p);
			p = n-1;
		} else {
			int mni = 0;
			fore(i,0,k) {
				if (deck[i] < deck[mni]) mni = i;
			}
			m -= deck[mni];
			if (m < 0) break;
			f(mni);
			p--;
		}
	}
	cout<<ans<<'\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	cin >> t;
	while(t--)  solve();
	return 0;
}
