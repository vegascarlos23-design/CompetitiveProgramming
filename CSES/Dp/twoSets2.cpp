#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

void solve() {
	int n; cin>>n;
	
	long long total = n*(n+1)/2;
	if (total & 1) {
		cout<<0;
		return;
	}

	long long sum = total/2;
	vector<vector<long long>> dp(n+1, vector<long long> (sum+1));
	
	dp[0][0] = 1;

	for(int c = 1; c < n; c++) {
		for(int x = 0; x <= sum; x++) {
			dp[c][x] = dp[c-1][x];
			if (x-c >= 0) dp[c][x] = (dp[c][x] + dp[c-1][x-c])%MOD;
		}
	}
	cout<<dp[n-1][sum];
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
