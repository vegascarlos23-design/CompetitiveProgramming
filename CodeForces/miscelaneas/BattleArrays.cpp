#include <bits/stdc++.h>
#include <vector>

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

void solve(){
	ll n,m; cin>>n>>m;
	priority_queue<ll> v1,v2;

	fore(i,0,n) {
		ll a; cin>>a;
		v1.push(a);
	}
	fore(i,0,m) {
		ll b; cin>>b;
		v2.push(b);
	}
	ll x,y,dif;
	while(!v1.empty() && !v2.empty()) {
		x = v1.top();
		y = v2.top();
		if (x >= y) {
			v2.pop();
		} else {
			dif =  y - x;
			v2.pop(); v2.push(dif);
		}
		
		if (v2.empty()) break;
		
		x = v1.top();
		y = v2.top();
		if (y >= x) {
			v1.pop();
		} else {
			dif = x - y;
			v1.pop(); v1.push(dif);
		}
	}

	cout << (v1.empty() ? "Bob" : "Alice") <<'\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	cin >> t;
	while(t--)  solve();
	return 0;
}
