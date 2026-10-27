#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n,a,b; cin>>n>>a>>b;

	vector<int> o1(a),o2(b);
	for(auto &x : o1) cin>>x;
	for(auto &x : o2) cin>>x;

	vector<int> v;
	map<int,int> mp;
	for(int i = 0; i < a; i++) {
		mp[o1[i]] = i+1;
	}

	for(int i = 0; i < b; i++) {
		if (!mp.count(o2[i])) continue;
		v.push_back(mp[o2[i]]);
	}

	//for (int i = 0; i < b; i++) cout<<v[i]<<" ";
	vector<int> lis;

	for(auto &x : v) {
		auto it = lower_bound(lis.begin(), lis.end(), x);
		if (it == lis.end()) {
			lis.push_back(x);
		} else {
			*it = x;
		}
	}

	cout<< v.size() - lis.size() <<'\n';
		
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
