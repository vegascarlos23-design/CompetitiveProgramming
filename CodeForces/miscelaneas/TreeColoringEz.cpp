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

vvi adj;
vi deep, nd;
int ans;

void dfs(int u, int p){
	deep[u] = deep[p]+1;
	nd[deep[u]]++;
	ans = max(ans, nd[deep[u]]);
	int sum = 1;
	for(auto &v : adj[u]) {
		if (v == p) continue;
		dfs(v,u);
		sum++;
	}
	ans = max(ans,sum);
}

void solve(){
	int n; cin>>n;
	ans = 0; 
	adj.assign(n+1,{});
	deep.assign(n+1,0);
	nd.assign(n+1,0);
	
	fore(i,0,n-1) {
		int u,v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0);
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
