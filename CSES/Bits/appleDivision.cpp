#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin>>n;
	vector<long long> a(n); for(auto &x: a) cin>>x;

	long long ans = 1e18;
	for(int mask = 0; mask < (1 << n); mask++) {
		long long sumA = 0, sumB = 0;
		for(int i = 0; i < n; i++) {
			if (mask & (1<<i)) {
				sumA += a[i];
			} else {
				sumB += a[i];
			}
		}
		ans = min(ans, abs(sumA - sumB));
	}
	cout<<ans;
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
