#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9 + 7;

void solve() {
	int n, m; cin>>n>>m;
	vector<long long> v(n+1);
	for(int i = 1; i<= n; i++) {
		cin>>v[i];
	}

	vector<vector<long long>> dp(n+1, vector<long long> (m+1));
	
	if (v[1] == 0) {
		for(int i = 1; i <= m ; i++) {
			dp[1][i] = 1;
		}	
	} else {
		dp[1][v[1]] = 1; 
	}


	for(int i = 2; i <= n; i++) {
		if (v[i] == 0) {
			for(int j = 1; j <= m; j++) {
				dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
				
				if (j>1) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%MOD;
				if (j < m) dp[i][j] = (dp[i][j] + dp[i-1][j+1])%MOD;
			}
		} else {
			dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][v[i]])%MOD;
			
			if (v[i] > 1) dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][v[i] - 1])%MOD;
			if (v[i] < m) dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][v[i] + 1])%MOD;
		}	
	}
	
	long long ans = 0;
	for(int i = 1; i<= m; i++) {
		ans = (ans + dp[n][i])%MOD;
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
