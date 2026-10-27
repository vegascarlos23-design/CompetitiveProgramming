#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9 + 7;

void solve() {
	int n; cin>>n;
	vector<vector<int>> a(n, vector<int>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin>>a[i][j];
		}
	}

	vector<long long> dp(1<<n);
       	dp[0] = 1;
	
	for(int mask = 0; mask < (1<<n) ; mask++) {
		int man = __builtin_popcount(mask);
		if (man == n) continue;

		for(int woman = 0; woman < n; woman++) {
			if (mask & (1<<woman)) continue;
			if (!a[man][woman]) continue;
			
			dp[mask | (1<<woman)] = (dp[mask | (1<<woman)] + dp[mask]) % MOD;
		}
	}	

	cout<<dp[(1<<n) - 1];
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
