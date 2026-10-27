#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

void solve() {
	int n, m; cin>>n>>m;
	vector<string> G(n);

	for(int i = 0; i<n; i++) cin>>G[i];
	
	vector<vector<long long>> dp(n+1, vector<long long>(m+1));

	for(int i = 1; i <= n; i++) {
		if (G[i-1][0] == '#') break;
		else dp[i][1] = 1;
	}

	for(int j = 1; j <= m; j++) {
		if (G[0][j-1] == '#') break;
		else dp[1][j] = 1;
	}

	for(int i = 2; i <= n; i++) {
		for(int j = 2; j <= m; j++) {
			if (G[i-1][j-1] == '#') dp[i][j] = 0;
			else dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
		}
	}
	cout<<dp[n][m];
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
