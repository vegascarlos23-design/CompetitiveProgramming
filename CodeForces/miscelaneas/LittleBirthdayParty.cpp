#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../../cpp/debug.cpp"
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

ll MOD = 1e9+7;
vll fact(366), inv_fact(366);

ll mod_pow(ll a, ll e) {
	ll res = 1;
	a %= MOD;
	while(e) {
		if (e & 1) res = res*a%MOD;
		a = a*a%MOD;
		e >>= 1;
	}
	return res;
}

ll mod_inv(ll x) {
	return mod_pow(x, MOD - 2);
}

void precmp() {
	fact[0] = 1;
	fore(i,1,366) {
		fact[i] = fact[i-1]*i%MOD;
	}
	inv_fact[365] = mod_inv(fact[365]);
	for(int i = 365; i>= 1; i--) {
		inv_fact[i-1] = inv_fact[i]*i%MOD;
	}
}

void solve(){
	ll n,x; cin>>n>>x;
	ll k = n-x;

	if (k > 364) {
		cout<<"0"<<'\n';
		return;
	}
	
	ll comb = 1;
	fore(i,0,k) {
		ll tr = (n-i)%MOD;
		comb = comb*tr%MOD;
	}
	comb = comb*inv_fact[k]%MOD;
	ll perm = fact[364]*inv_fact[364 - k]%MOD;
	ll num = 365*comb%MOD;
	num = num*perm%MOD;
	ll deno = mod_pow(365,n);
	ll ans = num*mod_inv(deno)%MOD;
	cout<<ans<<'\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	precmp();
	int t = 1; 
	cin >> t;
	while(t--)  solve();
	return 0;
}
