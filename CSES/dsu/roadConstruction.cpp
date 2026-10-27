#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> p, size;
	int comp, mxComp = 1;

	DSU(int n) {
		p.resize(n+1);
		size.resize(n+1, 1);
		comp = n;
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
		mxComp = max(mxComp, size[x]);
		comp--;
		p[y] = x;
	}
	
	bool isUnited(int x, int y) {
		x = find(x);
		y = find(y);

		return (x == y);
	}
};


void solve() {
	int n,m; cin>>n>>m;
	DSU dsu(n);
	
	while(m--) {
		int x,y; cin>>x>>y;
		dsu.unite(x,y);
		cout<<dsu.comp << " " <<dsu.mxComp<<endl;
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
