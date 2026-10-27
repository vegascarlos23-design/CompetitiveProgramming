#include <bits/stdc++.h>

using namespace std;

void solve() {	
	int n; cin>>n;
	vector<int> v(n); for(auto &x:v) cin>>x;

	vector<int> lis;

	for(auto &x : v) {
		auto it = lower_bound(lis.begin(), lis.end(), x);
		if (it == lis.end()) {
			lis.push_back(x);
		} else {
			*it = x;
		}
	}

	cout<<lis.size();
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
