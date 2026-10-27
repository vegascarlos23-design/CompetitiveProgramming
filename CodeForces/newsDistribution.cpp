#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> p, size;

	DSU(int n) {
		p.resize(n+1,1);
		size.resize(n+1,1);

		for(int i = 1; i <= n; i++) {
			p[i] = i;
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
		p[y] = x;
	}

	int comp(int x) {
		return size[find(x)];
	}
	
};

void solve() {
	int n, m; cin>>n>>m;
	DSU dsu(n);

	while(m--) {
		int k; cin>>k;
		int lst = -1;
		while(k--) {
			int x; cin>>x;
			if (lst != -1) dsu.unite(x,lst);
			lst = x;
		}
	}

	for(int i = 1; i <= n; i++) {
		cout<< dsu.comp(i) << ' ';
	}
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
