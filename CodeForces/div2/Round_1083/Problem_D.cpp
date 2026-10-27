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

struct Node {
	int left = -1;
	int right = -1;
	int parent = -1;
};

vector<Node> build_cartesian(vector<int>& a) {
	int n = a.size();
	vector<Node> tree(n);
	stack<int> st;

	for(int i = 0; i < n; i++) {
		int last = -1;

		while(!st.empty() && a[st.top()] < a[i]) {
			last = st.top();
			st.pop();
		}

		if(!st.empty()) {
			tree[i].parent = st.top();
			tree[st.top()].right = i;
		}

		if(last != -1) {
			tree[last].parent = i;
			tree[i].left = last;
		}

		st.push(i);
	}

	return tree;
}

int dfs(int u, vector<Node>& tree) {
	if (u == -1) return 0;
	return 1 + max(dfs(tree[u].left, tree), dfs(tree[u].right, tree));
}

void solve(){ 
	int n; cin>>n;
	vi v(n); cinv(v,n);
	
	vector<Node> tree = build_cartesian(v);
	int root = -1;
	fore(i,0,n) {
		if (tree[i].parent == -1) {
			root = i;
			break;
		}
	}
	int depth = dfs(root, tree);
	cout<<n - depth<<'\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	cin >> t;
	while(t--)  solve();
	return 0;
}
