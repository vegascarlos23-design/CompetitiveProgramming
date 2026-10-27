#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9 + 7;

void solve() {
	int n; cin>>n;
	vector<int> a(n);
	for(int &x : a) cin>>x;

	vector<vector<long long>> dp(n+1, vector<long long> (2520));

	dp[0][1] = 1;
	for (int i = 1 ; i<=n; i++) {
		for (int r = 0 ; r < 2520; r++) {
			dp[i][r] = ( dp[i][r] + dp[i-1][r] ) % MOD;

			long long nr = (1LL * r * a[i-1]) % 2520;
			dp[i][nr] = (dp[i][nr] + dp[i-1][r]) % MOD;	
		}
	}

	cout<< dp[n][0] << endl;
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
