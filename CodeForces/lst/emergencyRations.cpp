#include <bits/stdc++.h>

using namespace std;

template <typename T, typename L, typename MergeOp, typename ApplyOp, typename MergeLazy>
class lazy_segment_tree{
private:
	int n;
	vector<T> tree;
	vector<L> lazy;
	MergeOp merge_op;
	ApplyOp apply_op;
	MergeLazy merge_lazy;
	T identity_value;
	L identity_lazy;

	void build(const vector<T>& a, int node, int l, int r){
		if(l == r){ tree[node] = a[l]; return; }

		int m = (l + r) >> 1;
		int x = node + 1, y = node + 2 * (m - l + 1);
		build(a, x, l, m);
		build(a, y, m + 1, r);
		tree[node] = merge_op(tree[x], tree[y]);
	}

	void push(int node, int l, int r){
		if(lazy[node] != identity_lazy){
			tree[node] = apply_op(tree[node], lazy[node], l, r);
			if(l != r){
				int m = (l + r) >> 1;
				int x = node + 1, y = node + 2 * (m - l + 1);
				lazy[x] = merge_lazy(lazy[x], lazy[node]);
				lazy[y] = merge_lazy(lazy[y], lazy[node]);
			}
			lazy[node] = identity_lazy;
		}
	}

	T query(int node, int l, int r, int ql, int qr){
		push(node, l, r);
		if(qr < l || r < ql) return identity_value;
		if(ql <= l && r <= qr) return tree[node];

		int m = (l + r) >> 1;
		int x = node + 1, y = node + 2 * (m - l + 1);
		T left = query(x, l, m, ql, qr);
		T right = query(y, m + 1, r, ql, qr);
		return merge_op(left, right);
	}

	void update(int node, int l, int r, int ql, int qr, L val){
		push(node, l, r);
		if(qr < l || r < ql) return;
		if(ql <= l && r <= qr){
			lazy[node] = merge_lazy(lazy[node], val);
			push(node, l, r);
			return;
		}

		int m = (l + r) >> 1;
		int x = node + 1, y = node + 2 * (m - l + 1);
		update(x, l, m, ql, qr, val);
		update(y, m + 1, r, ql, qr, val);
		tree[node] = merge_op(tree[x], tree[y]);
	}

public:
	lazy_segment_tree(const vector<T>& a, MergeOp merge_op, ApplyOp apply_op, MergeLazy merge_lazy, T identity_value, L identity_lazy)
	: n((int) a.size()), merge_op(merge_op), apply_op(apply_op), merge_lazy(merge_lazy), identity_value(identity_value), identity_lazy(identity_lazy) {
		tree.resize(4 * n, identity_value);
		lazy.resize(4 * n, identity_lazy);
		build(a, 1, 0, n - 1);
	}

	T query(int l, int r){
		return query(1, 0, n - 1, l, r);
	}

	void update(int l, int r, L val){
		update(1, 0, n - 1, l, r, val);
	}
};

void solve() {
	int q; cin>>q;
	
	vector<pair<char,long long>> queries(q);
	vector<int> coord;
	
	for(auto &[t,x] : queries) {
		cin>>t>>x;
		coord.push_back(x);
	}	

	coord.push_back(0);
	sort(coord.begin(), coord.end());
	coord.erase(unique(coord.begin(), coord.end()), coord.end());

	using T = long long;
	using L = long long;

	auto merge_op = [](long long a, long long b) {
		return min(a,b);
	};

	auto apply_op = [](long long a, long long b, int l, int r) {
		return a + b;
	};

	auto merge_lazy = [](long long a, long long b) {
		return a + b;
	};

	T identity_value = LLONG_MAX / 2;
	L identity_lazy = 0;

	vector<T> values(coord.begin(), coord.end());

	lazy_segment_tree<T, L, decltype(merge_op), decltype(apply_op), decltype(merge_lazy)> 
		lst(values, merge_op, apply_op, merge_lazy, identity_value, identity_lazy);

	for(auto &[t,c] : queries) {
		int delta;
		if (t == '-') delta = -1;
		else delta = 1;

		int pos = lower_bound(coord.begin(), coord.end(), c) - coord.begin();

		if (pos > 0) lst.update(0,pos - 1, delta);

		cout<<lst.query(0, (int)coord.size() - 1) << '\n';
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
