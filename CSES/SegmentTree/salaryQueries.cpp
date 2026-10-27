#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
	int n;
	vector<long long> tree;

	SegmentTree(int n) {
		this -> n = n;
		tree.resize(4*n);
	}

	long long query(int node, int l, int r, int ql, int qr) {
		if (r < ql || qr < l) return 0;

		if (ql <= l && r <= qr) return tree[node];

		int mid = (l+r)/2;

		return query(node * 2, l, mid, ql,qr) + query(node * 2 + 1, mid+1,r,ql,qr);
	}	

	void update(int node, int l, int r, int pos, long long val) {
		if (l == r) {
			tree[node] += val;
			return;
		}	

		int mid = (l+r)/2;

		if (pos <= mid) update(node * 2, l, mid, pos, val);
		else update(node * 2 + 1, mid+1 , r , pos , val);

		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
};

struct Query {
	char type;
	int a,b;
};

void solve() {
	int n,q; cin>>n>>q;
	vector<long long> salary(n), comp; 
	
	for(auto &x : salary) {
		cin>>x;
		comp.push_back(x);
	}

	vector<Query> queries(q);

	for(int i = 0; i < q; i++) {
		char t; int a,b; cin>>t>>a>>b;

		queries[i] = {t,a,b};

		if (t == '!') comp.push_back(b);
	}

	sort(comp.begin(), comp.end());

	comp.erase(unique(comp.begin(), comp.end()), comp.end());

	int m = comp.size();

	SegmentTree st(m);

	for(auto &x : salary) {
		int pos = lower_bound(comp.begin(), comp.end(), x) - comp.begin();

		st.update(1,0,m-1,pos,1);
	}
	
	for (auto [t,a,b] : queries) {
		if (t == '!') {
			int k = a - 1;
			int oldPos = lower_bound(comp.begin(),comp.end() , salary[k]) - comp.begin();
			int newPos = lower_bound(comp.begin(),comp.end() , b) - comp.begin();

			st.update(1,0,m-1,oldPos, -1);
			st.update(1,0,m-1,newPos,1);
			salary[k] = b;
		} else {
			int l = lower_bound(comp.begin(), comp.end(), a) - comp.begin();
			int r = upper_bound(comp.begin(), comp.end(), b) - comp.begin() - 1; 

			if (l > r) cout << 0;
			else cout<< st.query(1,0,m-1,l,r);
			cout<<endl;
		}
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

