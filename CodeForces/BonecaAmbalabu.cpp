#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n; cin>>n;
	vector<long long> v(n); for(auto &x: v) cin>>x;

	vector<long long> bits(30);
	for(int i = 0; i < 30; i++) {
		for(int j = 0; j < n; j++) {
			if (v[j] & (1<<i)) bits[i]++; 
		}
	}
	
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		long long cur = 0;
		for(int j = 0; j < 30; j++) {
			if (v[i] & (1<<j)) {
				cur += (n - bits[j]) * (1 << j); 
			} else {
				cur += bits[j] * (1 << j);
			}
		}
		ans = max(ans, cur);
	}
	cout<<ans<<'\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}
