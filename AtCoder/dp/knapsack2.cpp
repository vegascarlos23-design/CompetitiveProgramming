#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

void solve() {
	long long n, w; cin>>n>>w;
	vector<long long> gain(n + 1), weight(n + 1);
	
	int MAXV = 0;
	for(int i = 1; i <= n; i++) {
		cin>>weight[i]>>gain[i];
		MAXV += gain[i];
	}

	vector<vector<long long>> dp(n+1, vector<long long> (MAXV + 1, INF));
	dp[0][0] = 0;
	
	for(int i = 1; i <= n; i++) {
		for(int k = 0; k <= MAXV; k++) {
			dp[i][k] = dp[i-1][k];
			if (k - gain[i] >= 0) dp[i][k] = min(dp[i][k] ,dp[i-1][k - gain[i]] + weight[i]);
		}	
	}
	long long ans = 0;
	for(long long i = 0; i <= MAXV; i++) {
		if (dp[n][i] > w) continue;
		ans = max(ans, i);
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
