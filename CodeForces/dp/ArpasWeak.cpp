
#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> p, size, wes, gns;

	DSU(int n, vector<int> wg, vector<int> gn) {
		p.resize(n+1,1);
		size.resize(n+1, 1);
		wes.resize(n+1);
		gns.resize(n+1);
		
		for(int i = 1; i <= n; i++) {
			p[i] = i;
			wes[i] = wg[i-1];
			gns[i] = gn[i-1];
		}
	}

	int find(int x) {
		if (x == p[x]) return x;
		return p[x] = find(p[x]);
	}
	
	void unite(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) return;
		if (size[x] < size[y]) swap(x,y);
		size[x] += size[y];
		wes[x] += wes[y];
		gns[x] += gns[y];
		p[y] = x;
	}
	
	int weight(int x) {
		x = find(x);
		return wes[x];
	}
	
	int gain(int x) {
		x = find(x);
		return gns[x];
	}
};


void solve() {
	int n,m,w; cin>>n>>m>>w;
	vector<int> wg(n),gn(n);
	for(auto &x : wg) cin>>x;
	for(auto &x : gn) cin>>x;

	DSU dsu(n, wg , gn);
	while(m--) {
		int x,y; cin>>x>>y;
		dsu.unite(x,y);
	}
	
	/*
	for(int i = 1; i <= n; i++) {
		cout << dsu.find(i) << " " << dsu.weight(i) << " " << dsu.gain(i) << endl;
	} */
	
	vector<int> id(n+1);
	vector<int> roots(n+1);
	int cm = 0;
	
	for(int i = 1; i <= n; i++) {
		int root = dsu.find(i);

		if (id[root] == 0) {
			id[root] = ++cm;
			roots[cm] = root;
		}
	}

	vector<vector<int>> comp(cm+1);

	for(int i = 1; i <= n; i++) {
		comp[id[dsu.find(i)]].push_back(i);
	}

	vector<vector<int>> dp(cm+1, vector<int> (w+1));

	for(int i = 1; i <= cm; i++) {
		for(int cw = 1; cw <= w; cw++) {
			dp[i][cw] = dp[i-1][cw];
			if (cw - dsu.weight(roots[i]) >= 0) {
				dp[i][cw] = max(dp[i][cw], dp[i-1][cw - dsu.weight(roots[i])] + dsu.gain(roots[i]));
			}

			for (auto &x : comp[i]) {
				if (cw - wg[x-1] >= 0) {
					dp[i][cw] = max(dp[i][cw], dp[i-1][cw - wg[x-1]] + gn[x-1]);
				}
			}
		}
	}

	cout<<dp[cm][w];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}
